#include <iostream>
#include <random> // 랜덤 라이브러리 포함
#include "BattleSystem.h"

using namespace std;




BattleSystem(Player*& player, Monster*& monster)
    :player(player), monster(monster)
{

}





void BattleStart()
{
    while (true)
    {
        if (monster == nullptr)
        {
            // monster = new NormalMonster;   //monster 몬스터생성하는 부분
        }

        cout << "\n\n========전투시작!=======\n\n";


        while (!player->IsDeath() && !monster->IsDeath())
        {

            cout << "플레이어가 공격합니다!\n\n";

            player->Attack();  //공격


            if (!player->IsDeath() && monster->IsDeath)
            {
                cout << "전투승리!\n\n";

                monster->Isdeath();




                delete monster;
                monster = nullptr;
            }
            else if (player->IsDeath() && !monster->IsDeath())
            {
                player->IsDeath();
                cout << "전투 배패!\n 게임을 종료합니다.";
    

            }
            else if (!player->IsDeath() && !monster->IsDeath())
            {

                cout << "전투를 지속합니다!\n\n";


                cout << "적의 공격!\n";


                monster->Attack();
            }


        }

        cout << "=====메뉴를 선택하세요=====\n\n";
        cout << "1. 전투로 돌아간다\n";
        cout << "2. 상점입장\n";
        cout << "3. 인벤토리 확인\n";
        cout << "선택: ";
        while (ismenu)
        {
            int choice;
            cin << choice;

            switch (choice)
            {
            case 1:
            {
                break;
                ismenu = false;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            }
        }
        

    }
}