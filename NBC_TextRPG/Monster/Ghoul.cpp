#include "Monster.h"
#include "Ghoul.h"
#include "../Player.h"
#include "../Manager/PlayerManager.h"


Ghoul::Ghoul(MonsterData monsterData) : Monster(monsterData)
{
    cout << "구울 생성";
    SetExp(20);
    SetGold(15);
    
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack()
{
    GetPlayer()->TakeDamage(monsterData.mATK);
    cout << "카구네 휘두르기: 찰싹!";
}

