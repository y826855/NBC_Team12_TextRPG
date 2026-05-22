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
        while((player->GetHp() > 0) && (monster->GetHP > 0))
        {
            cout << "전투시작!\n\n";

            player->PlayerAttack();
            cout << "플레이어가 공격합니다!";


            if ((player->GetHp() > 0) && (monster->GetHP > 0))
            {
                cout << "전투승리!\n";

                monster->GetDeath() = true;

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
            }
        }
    }
};



int main(int argc, char* argv[])
{



    
    return 0;
}
