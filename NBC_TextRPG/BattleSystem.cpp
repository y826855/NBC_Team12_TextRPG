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
    while (true)
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
            }
            else if (player->IsDeath() && !monster->IsDeath())
            {
                cout << "전투 배패!\n 게임을 종료합니다.";
                return;
    

            }
            else if (!player->IsDeath() && !monster->IsDeath())
            {

                cout << "전투를 지속합니다!\n\n";

                cout << "적의 공격!\n";


                monster->Attack();
            }

        }

        ChoiceMenu();
        
    }
}



void BattleSystem::PlayerAttack()
{
    int damage = player->GetATK();
    monster->TakeDamage(damage);
}


void BattleSystem::MonsterAttack()
{
    int damage = monster->GetATK();
    player() ===>TakeDamage(damage);
}


void BattleSystem::BattleReward()
{
    
}


void BattleSystem::ItemReward()
{
    
}


void BattleSystem::ChoiceMenu()
{

    bool ismenu = true;

    while (ismenu)
    {
        cout << "=====메뉴를 선택하세요=====\n\n";
        cout << "1. 전투로 돌아간다\n";
        cout << "2. 상점입장\n";
        cout << "3. 인벤토리 확인\n";
        cout << "선택: ";

        int choice;
        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            ismenu = false;
            break;
        }
        case 2:
        {
            //Shop
            break;
        }
        case 3:
        {
            ismenu = false;
            break;
        }
        }
    }
}