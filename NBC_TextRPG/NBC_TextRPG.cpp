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
        if ((player->GetHp() > 0) && (monster->GetHP > 0))
        {
            cout << "전투시작!\n\n";
        }
    }
};



int main(int argc, char* argv[])
{



    
    return 0;
}
