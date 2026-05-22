#include "Monster.h"
#include "Ghoul.h"


Ghoul::Ghoul(MonsterData monsterData) : Monster(monsterData)
{
    cout << "구울 생성";
    SetExp(20);
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack(Player* player)
{
    
    cout << "카구네 휘두르기: 찰싹!";
}

