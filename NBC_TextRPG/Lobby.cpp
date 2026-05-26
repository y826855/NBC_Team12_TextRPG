#include "Lobby.h"

#include "BattleSystem.h"
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
    Inventory* inventory =Inventory::GetInstance();
    //TODO 패배 처리 해야함
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
                // 게임 오버!
                return;   
            }
            break;
        case LobbyState::Shop:
            //TODO : 초기화 부분 수정필요
           
            m_Shop->OpenShop(inventory);
            break;
        default: break;
        }
        
    }
}
