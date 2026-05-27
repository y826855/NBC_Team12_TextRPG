#include "ConsoleController.h"

#include <iostream>

#include "MultiConsoleManager.h"

using namespace std;

ConsoleController::~ConsoleController()
{
    for (auto& pair : m_managers)
        delete pair.second;
    m_managers.clear();
}

bool ConsoleController::Initialize(int argc, char* argv[])
{
    // 임시 객체로 자식 모드인지 확인
    MultiConsoleManager temp;
    return temp.Initialize(argc, argv);
}

void ConsoleController::AddConsole(EConsoleTag tag)
{
    // 태그별 위치/크기 설정 정보 정의
    static map<EConsoleTag, ConsoleWindowConfig> configs = {
        { EConsoleTag::Main,             { 100, 40,  860, 915, 80, 25 } },
        { EConsoleTag::UpperRight,       { 945, 40,  870, 450, 80, 20 } },
        { EConsoleTag::LowerRight,       { 945, 500, 870, 450, 80, 20 } },
        { EConsoleTag::LargePopup,       { 420, 15, 1040, 1050, 120, 50 } },
        { EConsoleTag::SmallPopup,       { 740, 360, 400, 300, 60, 20 } },
    };

    // 메인 윈도우 처리
    if (tag == EConsoleTag::Main)
    {
        HWND mainHwnd = GetConsoleWindow();
        if (mainHwnd != nullptr)
        {
            SetWindowPos(mainHwnd, nullptr, configs[tag].x, configs[tag].y, configs[tag].width, configs[tag].height, SWP_NOZORDER);
        }
        return;
    }

    if (m_managers.find(tag) == m_managers.end())
    {
        m_managers[tag] = new MultiConsoleManager();
    }

    if (!m_managers[tag]->IsConnected())
    {
        // 설정된 좌표 정보를 매니저에게 전달
        m_managers[tag]->RunParentMode(TagToString(tag), configs[tag]);
    }
}

void ConsoleController::Message(EConsoleTag tag, const string& message)
{
    // 메인 콘솔은 직접 출력
    if (tag == EConsoleTag::Main)
    {
        cout << "[" << TagToString(tag) << "] " << message << endl;
        return;
    }

    // 1. 연결 확인 및 자동 생성
    if (m_managers.find(tag) == m_managers.end() || !m_managers[tag]->IsConnected())
    {
        AddConsole(tag);
    }

    // 2. 태그가 포함된 메시지 포맷팅
    string formattedMessage = " " + message;

    // 3. 메시지 전송
    if (!m_managers[tag]->SendToChild(formattedMessage))
    {
        // 전송 실패(창이 수동으로 닫힘 등) 시 재시도
        AddConsole(tag);
        m_managers[tag]->SendToChild(formattedMessage);
    }
}

void ConsoleController::Message(const string& message)
{
    Message(EConsoleTag::UpperRight, message);
}

void ConsoleController::CloseConsole(EConsoleTag tag)
{
    if (m_managers.count(tag) && m_managers[tag]->IsConnected())
    {
        m_managers[tag]->SendToChild("exit");
    }
}

void ConsoleController::Clear(EConsoleTag tag)
{
    if (tag == EConsoleTag::Main)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord = { 0, 0 };
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD written;

        if (GetConsoleScreenBufferInfo(hConsole, &csbi))
        {
            // 화면 전체를 공백으로 채움
            FillConsoleOutputCharacterA(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
            // 속성 초기화
            FillConsoleOutputAttribute(hConsole, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
            // 커서 이동
            SetConsoleCursorPosition(hConsole, coord);
        }
        return;
    }

    if (m_managers.count(tag) && m_managers[tag]->IsConnected())
    {
        m_managers[tag]->SendToChild("clear");
    }
}

void ConsoleController::CloseAll()
{
    for (auto const& pair : m_managers)
    {
        MultiConsoleManager* manager = pair.second;
        if (manager->IsConnected())
        {
            manager->SendToChild("exit");
        }
    }
}


string ConsoleController::TagToString(EConsoleTag tag)
{
    switch (tag)
    {
    case EConsoleTag::Main:         return TITLE_MAIN;
    case EConsoleTag::UpperRight:   return TITLE_UPPER_RIGHT;
    case EConsoleTag::LowerRight:   return TITLE_LOWER_RIGHT;
    case EConsoleTag::LargePopup:   return TITLE_LARGE_POPUP;
    case EConsoleTag::SmallPopup:   return TITLE_SMALL_POPUP;
    default: return "Unknown";
    }
}
