#include "Monster.h"
#include "Lich.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Lich::Lich() : Monster()
{
    monsterData = {"리치", 0,0,50,50,EItem::LichBone};
    SetStat();
    cout << "리치 생성";
}

Lich::~Lich()
{
}

void Lich::Attack()
{
    GetPlayer()->TakeDamage(monsterData.mATK);
    cout << "지옥의 비행: 슈우우욱!";
}

