#include <iostream>
#include <random>
#include "BattleSystem.h"

#include "Player.h"
#include "Item/Inventory.h"
#include "Item/ItemManager.h"
#include "Manager/PlayerManager.h"
#include "Monster/Boss.h"
#include "Monster/Ghoul.h"
#include "Monster/Hillbilly.h"
#include "Monster/Lich.h"
#include "MultiConsole/ConsoleController.h"
#include "MultiConsole/ConsoleLogStream.h"
#include "Utility/InputHelper.h"


using namespace std;


BattleSystem::BattleSystem()
: player(), monster()
{
    monster = nullptr;
    player = nullptr;
}

int BattleSystem::GetRandom(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void BattleSystem::MonsterSpawn()
{
    if (monster != nullptr) return;
    int MonsterNumber = GetRandom(1, 3);

    switch (MonsterNumber)
    {
    case 1:
        {
            monster = new Ghoul();
            break;
        }
    case 2:
        {
            monster = new Hillbilly();
            break;
        }
    case 3:
        {
            monster = new Lich();
            break;
        }
    }
}

void BattleSystem::BattleStart()
{
    if (!isBossSpawn) //일반 전투 
        NormalBattleLoop();
    
    else //보스 전투 
        BossBattleLoop();

    BattleReward();

    delete monster;
    monster = nullptr;
}

bool BattleSystem::IsGameOver()
{
    return bIsGameOver;
}

void BattleSystem::PlayerDie()
{
    cout << "전투 배패!\n 게임을 종료합니다.";
    bIsGameOver = true;
    C_LOG(EConsoleTag::SmallPopup) << "\n\n---------플레이어 사망---------\n\n";
}

void BattleSystem::EndTurnPhase()
{
    Inventory::GetInstance()->UseItemInBattlePhase();
    cout << "\n\n[전투를 지속합니다!]\n\n";
}

void BattleSystem::NormalBattleLoop()//
{\
    MonsterSpawn();
    player = GetPlayer();

    cout << "\n\n========전투 시작!=======\n\n";
    
    while (true)
    {

        std::cout << "--------------------------------\n";
        std::cout << " 행동을 선택하세요:\n";
        std::cout << " [1] 공격하기  [2] 포션 마시기\n";
        std::cout << "--------------------------------\n";
        

        int input = InputHelper::GetValidInput("입력 : ",1,2);
        bool completedTurn = false;
        
        switch (input)
        {
        case 1:
            std::cout << "\n\n [플레이어가 공격합니다!]\n\n";
            player->Attack(monster);  
            completedTurn = true; // 공격을 완료했으므로 턴 종료 조건 충족
            break;

        case 2:
            std::cout << "\n\n [가방에서 포션을 꺼냅니다!]\n\n";
            Inventory::GetInstance()->UseItemInBattlePhase();
            // TODO: 포션 마시는 로직 구현 (예: player->UsePotion() 등)
          
            completedTurn = true; 
            break;

        default:
            std::cout << "\n 올바른 번호를 선택해 주세요 (1 또는 2).\n\n";
            break;
        }
        
        // 유효하지 않은 행동(번호 잘못 입력 등)을 했다면 몬스터가 공격하면 안 되므로 스킵
        if (!completedTurn)
        {
            continue; 
        }
        
        if (monster->IsDeath())
        {
            cout << "\n\n[전투 승리!]\n\n";
            
            BattleReward();
                
            //TODO: 상점입장 선택
            BossCheck();
            
            break;
        }
        
        std::cout << "[몬스터의 턴!]\n";
        monster->Attack();
       
        
        if (player->IsDeath())
        {
            PlayerDie();
            break;
        }
        EndTurnPhase();
    }
}//일반몬스터 전투


void BattleSystem::BossBattleLoop()
{
    monster = new Boss();

    cout << "\n\n========보스 전투 시작!=======\n\n";
    
    while (true)
    {

        cout << "\n\n플레이어가 공격합니다!\n\n";

        player->Attack(monster);  

        if (monster->IsDeath())
        {
            cout << "게임클리어!\n\n";

            bIsGameOver = true;
                
            break;
        }
        else if (player->IsDeath())
        {
            PlayerDie();
            break;
        }
        else
        {
            monster->Attack();
            EndTurnPhase();
        }
    }
}//보스전투


void BattleSystem::BattleReward()
{
    int exp=monster->GetExp();
    int gold=monster->GetDropGold();
    
    player->AddExp(exp);
    player->AddGold(gold);
    
    Inventory::GetInstance()->AddItem(monster->GetDropItem(), 1);
}


void BattleSystem::ItemReward()
{
    
}


void BattleSystem::BossCheck()
{
    if (player->GetLevel()>=10)
    {
        isBossSpawn=true;
        
        cout<<"\n ==이제 일반 몬스터는 상대도 안 된다!==\n\n";
    }
}
