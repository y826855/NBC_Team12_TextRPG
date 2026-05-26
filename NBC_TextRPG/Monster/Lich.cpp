#include "Monster.h"
#include "Lich.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Lich::Lich(MonsterData monsterData) : Monster(monsterData)
{
    cout << "리치 생성";
    SetName("리치");
    SetExp(30);
    SetGold(20);
    SetDropItem(EItem::LichBone);

}

Lich::~Lich()
{
}

void Lich::Attack()
{
    GetPlayer()->TakeDamage(monsterData.mATK);
    cout << "지옥의 비행: 슈우우욱!";
}

