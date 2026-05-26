#include "Lobby.h"

#include "BattleSystem.h"
#include "TextPrinter.h"
#include "Item/Inventory.h"
#include "Manager/PlayerManager.h"
#include "MultiConsole/ConsoleController.h"
#include "Utility/InputHelper.h"

Lobby::Lobby()
{
    m_BattleSystem = new BattleSystem();
    m_Shop = new Shop();
}

void Lobby::Intro()
{
    //플레이어 생성
    SetNameByInput()
    //플레이어 init
}

void Lobby::ShowMenu()
{
    cout << endl;
    cout << "1. 전투" << endl;
    cout << "2. 상점" << endl;
}

void Lobby::ChoiceMenu()
{
    int input = InputHelper::GetValidInput("입력 :", 1, 2);
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
