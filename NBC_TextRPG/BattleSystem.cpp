#include <iostream>
#include <random>
#include "BattleSystem.h"

#include "Player.h"
#include "Item/ItemManager.h"
#include "Manager/PlayerManager.h"
#include "Monster/Ghoul.h"


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
            MonsterData data = {"구울1", 30, 1, 5, 50, EItem::Berry};
            monster = new Ghoul(data);
            break;
        }
    case 2:
        {
            MonsterData data = {"구울2", 30, 1, 5, 50, EItem::Berry};
            monster = new Ghoul(data);
            break;
        }
    case 3:
        {
            MonsterData data = {"구울3", 30, 1, 5, 50, EItem::Berry};
            monster = new Ghoul(data);
            break;
        }
    }
}

void BattleSystem::BattleStart()
{
    if (!isBossSpawn)   //일반 전투
    {    
        cout << "\n\n일반 전투 시작\n\n";
        NormalBattleLoop();
    }

    else // 보스 전투
    {
        BossBattleLoop();
    }
}

bool BattleSystem::IsGameOver()
{
    return bIsGameOver;
}

void BattleSystem::PlayerDie()
{
    cout << "전투 배패!\n 게임을 종료합니다.";
    bIsGameOver = true;
}

void BattleSystem::NormalBattleLoop()//
{
    MonsterSpawn();
    player = GetPlayer();

    cout << "\n\n========전투시작!=======\n\n";
    
    while (true)
    {

        cout << "플레이어가 공격합니다!\n\n";

        player->Attack(monster);  

        if (monster->IsDeath())
        {
            cout << "\n\n전투승리!\n\n";
                
            delete monster;
            monster = nullptr;
            bIsGameOver = true;
            
            //BattleReward();
            //TODO: 상점입장 선택
            //BossCheck();
            
            break;
        }
        else if (player->IsDeath())
        {
            PlayerDie();
            break;
        }
        else
        {
            cout << "전투를 지속합니다!\n\n";
            monster->Attack();
        }
    }
}//일반몬스터 전투


void BattleSystem::BossBattleLoop()
{
    //monster=new bossmonster; 보스생성
    player = GetPlayer();

    cout << "\n\n========전투시작!=======\n\n";
    
    while (true)
    {

        cout << "플레이어가 공격합니다!\n\n";

        player->Attack(monster);  

        if (monster->IsDeath())
        {
            cout << "게임클리어!\n\n";
                
            delete monster;
            monster = nullptr;
            bIsGameOver = true;
                
            //BattleReward();
            
            break;
        }
        else if (player->IsDeath())
        {
            PlayerDie();
            break;
        }
        else
        {
            cout << "전투를 지속합니다!\n\n";
            monster->Attack();
        }
    }
}//보스전투


void BattleSystem::BattleReward()
{
    int exp=monster->GetExp();
    int gold=monster->GetDropGold();
    
    player->AddExp(exp);
    //player->AddGold(gold);
}


void BattleSystem::ItemReward()
{
    
}


void BattleSystem::BossCheck()
{
    if (player->GetLevel()>=10)
    {
        isBossSpawn=true;
        
        cout<<"\n ==이제 일반 몬스터는 상대도 안 된다!==";
    }
}
