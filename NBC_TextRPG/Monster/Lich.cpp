#include "Monster.h"
#include "Lich.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Lich::Lich() : Monster()
{
    monsterData = {"리치", 0,0,50,50,EItem::LichBone};
    SetStat();
    cout << "\n\033[30;43m리치의 시선이 느껴진다...\033[0m";
}

Lich::~Lich()
{
}

void Lich::Attack()
{
    cout << "\033[30;43m지옥의 비행: 슈우우욱!\033[0m" << endl;
    GetPlayer()->TakeDamage(monsterData.mATK);
}

