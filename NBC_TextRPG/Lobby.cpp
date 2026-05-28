#include "Lobby.h"
#include "BattleSystem.h"
#include "TextPrinter.h"
#include "Manager/PlayerManager.h"
#include "MultiConsole/ConsoleController.h"
#include "Utility/InputHelper.h"

using namespace std;

Lobby::Lobby()
{
    m_BattleSystem = make_unique<BattleSystem>();
    m_Shop = make_unique<Shop>();
}

Lobby::~Lobby()
{
}

void Lobby::Intro()
{
    SetNameByInput()
}

void Lobby::ShowMenu()
{
    cout << endl;
    cout << "1. 전투" << endl;
    cout << "2. 상점" << endl;
}

void Lobby::ChoiceMenu()
{
    int input = InputHelper::GetValidInput("\n입력 :", 1, 2);
    switch (input)
    {
    case  1: m_LobbyState = LobbyState::Battle; break;
    case  2: m_LobbyState = LobbyState::Shop; break;
    }
}

void Lobby::ContentLoop()
{
    while (true)
    {
        ShowMenu();
        ChoiceMenu();
        
        switch (m_LobbyState)
        {
        case LobbyState::Battle:
            m_BattleSystem->BattleStart();
            if (m_BattleSystem->IsGameOver())
            {
                Sleep(2000);
                // 게임 오버!
                return;   
            }
            break;
        case LobbyState::Shop:
            m_Shop->OpenShop();
            break;
        default: break;
        }
        
    }
}
