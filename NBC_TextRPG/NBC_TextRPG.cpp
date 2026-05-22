#include <iostream>

using namespace std;



class BattleSystem
{

public:

    Player*& player;
    Monster*& monster;

    BattleSystem(Player* &player,Monster* &monster)
        :player(player),monster(monster),
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

            player->GetAttack();
            cout << "플레이어가 공격합니다!\n\n";


            while ((player->GetHp() > 0) && (monster->GetHP > 0))
            {



                if ((player->GetHp() > 0) && (monster->GetHP > 0))
                {
                    cout << "전투승리!\n\n";

                    monster->GetDeath() = true;

                    player->GetExp()+=player->GetExp + monster->GetExp

                    delete monster;
                    monster = nullptr;
                }
                else if ((player->GetHp() <= 0) && (monster->GetHP > 0))
                {
                    cout << "전투 배패!\n 게임을 종료합니다.";

                    player->GetDeath();
 
                }
                else if ((player->GetHp() > 0) && (monster->GetHP > 0))
                {
                    monster->GetDeath() = false;
                    cout << "전투를 지속합니다!\n\n";


                    cout<<"적이 공격"
                    monster->MonsterAttack();
                }


            }



        }
    }
};



int main(int argc, char* argv[])
{



    
    return 0;
}
