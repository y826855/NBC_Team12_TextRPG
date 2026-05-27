#include "Monster.h"
#include "Ghoul.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Ghoul::Ghoul() : Monster()
{
    monsterData = {"구울", 0,0,25,15,EItem::GhoulSkin};
    SetStat();
    cout << "구울 생성";
    
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack()
{
    cout << "카구네 휘두르기: 찰싹!";
    GetPlayer()->TakeDamage(monsterData.mATK);
}

