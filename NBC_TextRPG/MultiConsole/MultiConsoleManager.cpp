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
    if (argc > 1)
    {
        string arg = argv[1];
        if (arg.find("child_") == 0)
        {
            string tag = arg.substr(6);
            
            // 명령줄 인자로부터 좌표와 크기 파싱 (X, Y, W, H)
            int x = 850, y = 100, w = 600, h = 450;
            if (argc >= 6)
            {
                x = stoi(argv[2]);
                y = stoi(argv[3]);
                w = stoi(argv[4]);
                h = stoi(argv[5]);
            }

            RunChildMode(tag, x, y, w, h);
            return false;
        }
    }

    return true;
}

void MultiConsoleManager::RunParentMode(const string& tag, const ConsoleWindowConfig& config)
{
    if (hPipe != INVALID_HANDLE_VALUE)
    {
        return;
    }

    string pipeName = "\\\\.\\pipe\\NBC_RPG_" + tag;
    cout << "[Parent] " << tag << " 콘솔용 파이프 생성..." << endl;

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

    // 자식 프로세스 실행 인자에 좌표와 크기 정보를 포함시킴
    string cmdLine = "\"" + string(modulePath) + "\" child_" + tag + " " +
                     to_string(config.x) + " " + to_string(config.y) + " " +
                     to_string(config.width) + " " + to_string(config.height);
    
    STARTUPINFOA si = { sizeof(si) };
    // STARTF_USEPOSITION와 STARTF_USESIZE를 활성화
    si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
    si.dwX = config.x;
    si.dwY = config.y;
    si.dwXSize = config.cols;
    si.dwYSize = config.rows;

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

    cout << "[Parent] " << tag << " 자식 콘솔 연결 대기 중..." << endl;
    ConnectNamedPipe(hPipe, nullptr);
    cout << "[Parent] " << tag << " 연결 성공!" << endl;
}

void MultiConsoleManager::RunChildMode(const string& tag, int x, int y, int w, int h)
{
    string fullTitle = string(CONSOLE_TITLE_PREFIX) + tag;
    SetConsoleTitleA(fullTitle.c_str());
    string pipeName = "\\\\.\\pipe\\NBC_RPG_" + tag;

    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
    {
        SetWindowPos(hwnd, NULL, 
            x, y, 
            w, h, 
            SWP_NOZORDER | SWP_SHOWWINDOW);
    }

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

    cout << "[Child] 연결되었습니다. 메시지 수신 대기 중...\n\n" << endl;

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
            else if (msg == "clear")
            {
                // system("cls") 대신 Windows API를 사용하여 화면을 지웁니다.
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD coord = { 0, 0 };
                CONSOLE_SCREEN_BUFFER_INFO csbi;
                DWORD written;

                // 콘솔 버퍼의 현재 정보를 가져옵니다 (크기, 속성 등)
                if (GetConsoleScreenBufferInfo(hConsole, &csbi))
                {
                    // 1. 화면 전체를 공백(' ')으로 채웁니다.
                    FillConsoleOutputCharacterA(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
                    // 2. 화면 전체의 속성(색상 등)을 현재 설정으로 초기화합니다.
                    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
                    // 3. 커서를 좌측 상단(0, 0)으로 이동시킵니다.
                    SetConsoleCursorPosition(hConsole, coord);
                }
                continue;
            }
            cout << msg << endl;
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