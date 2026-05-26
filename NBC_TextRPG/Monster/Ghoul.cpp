#include "Monster.h"
#include "Ghoul.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Ghoul::Ghoul(MonsterData monsterData) : Monster(monsterData)
{
    cout << "구울 생성";
    SetName("구울");
    SetExp(20);
    SetGold(15);
    SetDropItem(EItem::GhoulSkin);
    
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack()
{
    GetPlayer()->TakeDamage(monsterData.mATK);
    cout << "카구네 휘두르기: 찰싹!";
}

