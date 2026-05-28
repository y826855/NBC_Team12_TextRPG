#include "Monster.h"
#include "Lich.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Lich::Lich(MonsterData monsterdata) : Monster()
{
    this->monsterData.mName = monsterdata.mName;
    this->monsterData.exp = monsterdata.exp;
    this->monsterData.gold = monsterdata.gold;
    this->monsterData.dropItem = monsterdata.dropItem;
    this->SetStat();
    cout << "\n\n*** 리치의 시선이 느껴진다... ***";
}

Lich::~Lich()
{
}

void Lich::Attack()
{
    cout << "지옥의 비행: 슈우우욱!\n" << endl;
    GetPlayer()->TakeDamage(mATK);
}

