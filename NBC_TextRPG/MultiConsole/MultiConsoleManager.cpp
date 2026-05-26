#include "MultiConsoleManager.h"
#include <iostream>
#include <string>

using namespace std;

MultiConsoleManager::MultiConsoleManager() 
    : hPipe(INVALID_HANDLE_VALUE), hChildProcess(nullptr)
{
}

MultiConsoleManager::~MultiConsoleManager()
{
    Cleanup();
}

bool MultiConsoleManager::Initialize(int argc, char* argv[])
{
    if (argc > 1 && string(argv[1]) == "child")
    {
        RunChildMode();
        return false;
    }

    return true;
}

void MultiConsoleManager::RunParentMode()
{
    if (hPipe != INVALID_HANDLE_VALUE)
    {
        return;
    }

    cout << "[Parent] 부모 콘솔 시작. 파이프를 생성합니다..." << endl;

    // 1. Named Pipe 생성 (단방향 - 쓰기용)
    hPipe = CreateNamedPipeA(
        pipeName.c_str(),
        PIPE_ACCESS_OUTBOUND,           // 부모 -> 자식 (Outbound)
        PIPE_TYPE_BYTE | PIPE_WAIT,     // 바이트 단위, 블로킹 모드
        1, bufferSize, bufferSize, 0, nullptr
    );

    if (hPipe == INVALID_HANDLE_VALUE)
    {
        cerr << "[Error] 파이프 생성 실패: " << GetLastError() << endl;
        return;
    }

    // 3. 자기 자신(.exe)을 새로운 콘솔 창으로 실행
    char modulePath[MAX_PATH];
    GetModuleFileNameA(nullptr, modulePath, MAX_PATH);

    string cmdLine = "\"" + string(modulePath) + "\" child";
    
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi = { 0 };

    if (CreateProcessA(nullptr, (LPSTR)cmdLine.c_str(),
                       nullptr,
                       nullptr,
                       FALSE,
                       CREATE_NEW_CONSOLE,
                       nullptr,
                       nullptr, &si, &pi))
    {
        hChildProcess = pi.hProcess;
        CloseHandle(pi.hThread); // 스레드 핸들은 사용하지 않으므로 닫음
    }
    else
    {
        cerr << "[Error] 자식 프로세스 생성 실패: " << GetLastError() << endl;
        return;
    }

    cout << "[Parent] 자식 콘솔 연결 대기 중..." << endl;
    ConnectNamedPipe(hPipe, nullptr);
    cout << "[Parent] 자식 콘솔(로그창) 연결 성공!" << endl;
}

void MultiConsoleManager::RunChildMode()
{
    SetConsoleTitleA("Child Console - Logger");
    cout << "[Child] 부모 파이프에 연결 중..." << endl;

    // 1. 파이프 연결 (CreateFile)
    while (true)
    {
        hPipe = CreateFileA(pipeName.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, 0, nullptr);
        if (hPipe != INVALID_HANDLE_VALUE) break;

        if (GetLastError() != ERROR_PIPE_BUSY)
        {
            Sleep(500); // 잠시 대기 후 재시도
            continue;
        }
        WaitNamedPipeA(pipeName.c_str(), 2000);
    }

    cout << "[Child] 연결되었습니다. 메시지 수신 대기 중..." << endl;

    // 2. 데이터 수신 루프 
    char buffer[512]; //TODO : 글자수 최대치를 올려야 할 수 있습니다.
    DWORD bytesRead;
    while (true)
    {
        if (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, nullptr) && bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            string msg(buffer);
            if (msg == "exit")
            {
                cout << "[Child] 종료 명령을 받았습니다." << endl;
                break;
            }
            cout << "[Received]: " << msg << endl;
        }
        else
        {
            // 파이프가 끊어지면 종료
            cout << "[Child] 파이프 연결이 끊어졌습니다." << endl;
            break;
        }
    }
    
    CloseHandle(hPipe);
    cout << "[Child] 3초 후 자동 종료됩니다..." << endl;
    Sleep(3000);
    exit(0); // 자식 프로세스는 여기서 완전히 종료
}

bool MultiConsoleManager::SendToChild(const string& message)
{
    if (hPipe == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD bytesWritten;
    BOOL result = WriteFile(
        hPipe,
        message.c_str(),
        static_cast<DWORD>(message.length()),
        &bytesWritten,
        nullptr
    );

    if (!result)
    {
        Cleanup(); // 전송 실패 시 핸들 정리
    }

    return result;
}

void MultiConsoleManager::Cleanup()
{
    if (hPipe != INVALID_HANDLE_VALUE)
    {
        CloseHandle(hPipe);
        hPipe = INVALID_HANDLE_VALUE;
    }
    
    if (hChildProcess != nullptr)
    {
        // 자식 프로세스가 종료될 때까지 기다리지 않고 핸들만 정리 (필요시 WaitForSingleObject 사용)
        CloseHandle(hChildProcess);
        hChildProcess = nullptr;
    }
}