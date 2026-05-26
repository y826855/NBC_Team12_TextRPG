#include "MultiConsoleManager.h"
#include <iostream>
#include <string>

MultiConsoleManager::MultiConsoleManager() 
    : hPipe(INVALID_HANDLE_VALUE), hChildProcess(NULL) {
}

MultiConsoleManager::~MultiConsoleManager() {
    Cleanup();
}

bool MultiConsoleManager::Initialize(int argc, char* argv[]) {
    // 1. 명령행 인자를 확인하여 모드 분기
    if (argc > 1 && std::string(argv[1]) == "child") {
        RunChildMode();
        return false; // 자식 모드는 여기서 종료
    } else {
        RunParentMode();
        return true;  // 부모 모드는 게임 로직을 계속 진행
    }
}

void MultiConsoleManager::RunParentMode() {
    std::cout << "[Parent] 부모 콘솔 시작. 파이프를 생성합니다..." << std::endl;

    // 1. Named Pipe 생성 (단방향 - 쓰기용)
    hPipe = CreateNamedPipeA(
        pipeName.c_str(),
        PIPE_ACCESS_OUTBOUND,           // 부모 -> 자식 (Outbound)
        PIPE_TYPE_BYTE | PIPE_WAIT,     // 바이트 단위, 블로킹 모드
        1, bufferSize, bufferSize, 0, NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) return;

    // 3. 자기 자신(.exe)을 새로운 콘솔 창으로 실행
    char modulePath[MAX_PATH];
    GetModuleFileNameA(NULL, modulePath, MAX_PATH);

    std::string cmdLine = "\"" + std::string(modulePath) + "\" child";
    
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi = { 0 };

    if (CreateProcessA(NULL, (LPSTR)cmdLine.c_str(), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
        hChildProcess = pi.hProcess;
        CloseHandle(pi.hThread); // 스레드 핸들은 사용하지 않으므로 닫음
    } else {
        std::cerr << "[Error] 자식 프로세스 생성 실패: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "[Parent] 자식 콘솔 연결 대기 중..." << std::endl;
    ConnectNamedPipe(hPipe, NULL); // 자식이 연결될 때까지 대기
    std::cout << "[Parent] 자식 콘솔(로그창) 연결 성공!" << std::endl;
}

void MultiConsoleManager::RunChildMode() {
    SetConsoleTitleA("Child Console - Logger");
    std::cout << "[Child] 부모 파이프에 연결 중..." << std::endl;

    // 1. 파이프 연결 (CreateFile)
    while (true) {
        hPipe = CreateFileA(pipeName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (hPipe != INVALID_HANDLE_VALUE) break;
        
        if (GetLastError() != ERROR_PIPE_BUSY) {
            Sleep(500); // 잠시 대기 후 재시도
            continue;
        }
        WaitNamedPipeA(pipeName.c_str(), 2000);
    }

    std::cout << "[Child] 연결되었습니다. 메시지 수신 대기 중..." << std::endl;

    // 2. 데이터 수신 루프
    char buffer[512];
    DWORD bytesRead;
    while (true) {
        if (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::string msg(buffer);
            
            if (msg == "exit") {
                std::cout << "[Child] 종료 명령을 받았습니다." << std::endl;
                break;
            }
            std::cout << "[Received]: " << msg << std::endl;
        } else {
            // 파이프가 끊어지면 종료
            std::cout << "[Child] 파이프 연결이 끊어졌습니다." << std::endl;
            break;
        }
    }
    
    CloseHandle(hPipe);
    std::cout << "[Child] 3초 후 자동 종료됩니다..." << std::endl;
    Sleep(3000);
    exit(0); // 자식 프로세스는 여기서 완전히 종료
}

bool MultiConsoleManager::SendToChild(const std::string& message) {
    if (hPipe == INVALID_HANDLE_VALUE) return false;

    DWORD bytesWritten;
    BOOL result = WriteFile(
        hPipe,
        message.c_str(),
        static_cast<DWORD>(message.length()),
        &bytesWritten,
        NULL
    );

    return result;
}

void MultiConsoleManager::Cleanup() {
    if (hPipe != INVALID_HANDLE_VALUE) {
        CloseHandle(hPipe);
        hPipe = INVALID_HANDLE_VALUE;
    }
    if (hChildProcess != NULL) {
        // 자식 프로세스가 종료될 때까지 기다리지 않고 핸들만 정리 (필요시 WaitForSingleObject 사용)
        CloseHandle(hChildProcess);
        hChildProcess = NULL;
    }
}