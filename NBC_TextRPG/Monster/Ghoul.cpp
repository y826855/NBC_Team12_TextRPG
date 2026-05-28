#include "Monster.h"
#include "Ghoul.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Ghoul::Ghoul(MonsterData monsterdata) : Monster()
{
    this->monsterData.mName = monsterdata.mName;
    this->monsterData.exp = monsterdata.exp;
    this->monsterData.gold = monsterdata.gold;
    this->monsterData.dropItem = monsterdata.dropItem;
    this->SetStat();
    cout << "\n\n*** 구울의 울음소리... ***";
    
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack()
{
    cout << "카구네 휘두르기: 찰싹!\n" << endl;
    GetPlayer()->TakeDamage(mATK);
}

