#include <iostream>
#include <random>
#include "BattleSystem.h"


using namespace std;




BattleSystem::BattleSystem(Player*& player, Monster*& monster)
    :player(player), monster(monster)
{

}


void BattleSystem::MonsterSpawn()
{
    if (monster == nullptr)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 3);  //1~3

        int MonsterNumber = dist(gen);

        switch (MonsterNumber)
        {
        case 1:
        {
            //monster = new monster1
            break;
        }
        case 2:
        {
            //monster = new monster2
            break;
        }
        case 3:
        {
            //monster = new monster3
            break;
        }
        }


    }
}

void BattleSystem::BattleStart()
{
    if (!isBossSpawn)   //일반전투
    {
        NormalBattleLoop();
    }
    
    if (!isClear)   //보스전투
    {
        BossBattleLoop();
    }
}

void BattleSystem::NormalBattleLoop()//
{
    while (!isBossSpawn)   //일반전투
    {
        MonsterSpawn();

        cout << "\n\n========전투시작!=======\n\n";


        while (!player->IsDeath() && !monster->IsDeath())
        {

            cout << "플레이어가 공격합니다!\n\n";

            player->Attack();  


            if (!player->IsDeath() && monster->IsDeath())
            {
                cout << "전투승리!\n\n";
                
                delete monster;
                monster = nullptr;
                
                BattleReward();
                
                //TODO: 상점입장 선택
                
                BossCheck();
                
            }
            else if (player->IsDeath() && !monster->IsDeath())
            {
                cout << "전투 배패!\n 게임을 종료합니다.";
                return;
    

            }
            else if (!player->IsDeath() && !monster->IsDeath())
            {

                cout << "전투를 지속합니다!\n\n";


                monster->Attack();
            }
        }
    }//일반전투
}//일반몬스터 전투


void BattleSystem::BossBattleLoop()
{
    while (!isClear)    //보스전투
    {
        if (monster == nullptr)
        {
            //monster=new bossmonster; 보스생성
        }
        
        while (!player->IsDeath() && !monster->IsDeath())
        {

            cout << "플레이어가 공격합니다!\n\n";

            player->Attack();  


            if (!player->IsDeath() && monster->IsDeath())
            {
                cout << "게임클리어!\n\n";
                
                delete monster;
                monster = nullptr;
                
                isClear=true;
                return;
            }
            else if (player->IsDeath() && !monster->IsDeath())
            {
                cout << "전투 배패!\n 게임을 종료합니다.";
                return;
                
            }
            else if (!player->IsDeath() && !monster->IsDeath())
            {
                cout << "전투를 지속합니다!\n\n";
                
                monster->Attack();
            }
        }
    }
}//보스전투


void BattleSystem::BattleReward()
{
    int exp=monster->GetExp();
    int gold=monster->GetDropGold();
    
    player->AddExp(exp);
    player->AddGold(gold);
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


// void BattleSystem::ChoiceMenu()
// {
//
//     bool ismenu = true;
//
//     while (ismenu)
//     {
//         cout << "=====메뉴를 선택하세요=====\n\n";
//         cout << "1. 전투로 돌아간다\n";
//         cout << "2. 상점입장\n";
//         cout << "3. 인벤토리 확인\n";
//         cout << "선택: ";
//
//         int choice;
//         InputHelper::GetValidInput(" ",1,3);
//
//
//         switch (choice)
//         {
//         case 1:
//         {
//             ismenu = false;
//             break;
//         }
//         case 2:
//         {
//             //Shop
//             break;
//         }
//         case 3:
//         {
//             ismenu = false;
//             break;
//         }
//         }
//     }
// }