#include "MultiConsole/MultiConsoleManager.h"
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
    std::cout << "[Parent] 부모 콘솔 시작. 자식 창을 생성합니다..." << std::endl;

    // 2. Named Pipe 생성 (부모 -> 자식 단방향 전송용)
    hPipe = CreateNamedPipeA(
        pipeName.c_str(),
        PIPE_ACCESS_OUTBOUND,
        PIPE_TYPE_BYTE | PIPE_WAIT,
        1, bufferSize, bufferSize, 0, NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) return;
    if (hPipe == INVALID_HANDLE_VALUE) {
        std::cerr << "[Error] 파이프 생성 실패: " << GetLastError() << std::endl;
        return; // Parent mode initialization failed
    }

    // 3. 자기 자신(.exe)을 새로운 콘솔 창으로 실행
    char modulePath[MAX_PATH];
    GetModuleFileNameA(NULL, modulePath, MAX_PATH);

    // 명령행 인자에 "child"를 붙여 실행
    std::string cmdLine = "\"" + std::string(modulePath) + "\" child";
    
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi = { 0 };

    // CREATE_NEW_CONSOLE 플래그를 사용하여 새로운 창을 띄움
    if (CreateProcessA(NULL, (LPSTR)cmdLine.c_str(), NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
        hChildProcess = pi.hProcess;
        CloseHandle(pi.hThread);
    }

    std::cout << "[Parent] 자식 콘솔 연결 대기 중..." << std::endl;
    ConnectNamedPipe(hPipe, NULL);
    std::cout << "[Parent] 자식 콘솔(로그창) 연결 성공!" << std::endl;
}

void MultiConsoleManager::RunChildMode() {
    SetConsoleTitleA("Child Console - Message Receiver");
    
    // 4. 부모가 만든 파이프에 연결
    while (true) {
        hPipe = CreateFileA(pipeName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (hPipe != INVALID_HANDLE_VALUE) break;
        
        if (GetLastError() == ERROR_PIPE_BUSY) {
            WaitNamedPipeA(pipeName.c_str(), 2000);
            continue;
        }
        Sleep(100);
    }

    std::cout << "[Child] 부모 콘솔과 연결되었습니다." << std::endl;

    char buffer[512];
    DWORD bytesRead;
    while (true) {
        // 5. 파이프에서 실시간으로 데이터 읽기
        if (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::string msg(buffer);
            if (msg == "exit") break;
            std::cout << "[Received]: " << msg << std::endl;
        } else {
            break; // 파이프 종료 시 탈출
        }
    }

    std::cout << "[Child] 연결이 종료되었습니다. 2초 후 창을 닫습니다." << std::endl;
    Sleep(2000);
    exit(0); // 자식 프로세스는 여기서 완전히 종료
}

bool MultiConsoleManager::SendToChild(const std::string& message) {
    if (hPipe == INVALID_HANDLE_VALUE) return false;
    DWORD bytesWritten;
    return WriteFile(hPipe, message.c_str(), (DWORD)message.length(), &bytesWritten, NULL);
}

void MultiConsoleManager::Cleanup() {
    if (hPipe != INVALID_HANDLE_VALUE) {
        CloseHandle(hPipe);
        hPipe = INVALID_HANDLE_VALUE;
    }
    if (hChildProcess != NULL) {
        CloseHandle(hChildProcess);
        hChildProcess = NULL;
    }
}