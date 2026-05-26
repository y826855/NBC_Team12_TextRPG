#include "ConsoleController.h"
#include "MultiConsoleManager.h"

using namespace std;

bool ConsoleController::Initialize(int argc, char* argv[])
{
    return m_manager.Initialize(argc, argv);
}

void ConsoleController::AddConsole()
{
    if (!m_manager.IsConnected())
    {
        m_manager.RunParentMode();
    }
}

void ConsoleController::Message(EConsoleTag tag, const string& message)
{
    // 1. 연결 확인 및 자동 생성
    if (!m_manager.IsConnected())
    {
        AddConsole();
    }

    // 2. 태그가 포함된 메시지 포맷팅
    string formattedMessage = "[" + TagToString(tag) + "] " + message;

    // 2. 메시지 전송
    if (!m_manager.SendToChild(formattedMessage))
    {
        // 전송 실패(창이 수동으로 닫힘 등) 시 재시도
        AddConsole();
        m_manager.SendToChild(formattedMessage);
    }
}

void ConsoleController::Message(const string& message)
{
    Message(EConsoleTag::Log, message);
}

void ConsoleController::CloseConsole(EConsoleTag tag)
{
    if (m_manager.IsConnected())
    {
        m_manager.SendToChild("exit");
    }
}

void ConsoleController::CloseAll()
{
    if (m_manager.IsConnected())
    {
        m_manager.SendToChild("exit");
    }
}

string ConsoleController::TagToString(EConsoleTag tag)
{
    switch (tag)
    {
    case EConsoleTag::Log:          return "Log";
    case EConsoleTag::Battle:       return "Battle";
    case EConsoleTag::Stat:         return "Stat";
    case EConsoleTag::Shop:         return "Shop";
    case EConsoleTag::Inventory:    return "Inventory";
    default: return "Unknown";
    }
}