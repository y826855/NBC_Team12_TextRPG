#include "Monster.h"
#include "Hillbilly.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Hillbilly::Hillbilly() : Monster()
{
    monsterData = {"힐빌리", 0,0,30,30,EItem::Chainsaw};
    SetStat();
    cout << "힐빌리 생성";
}

Hillbilly::~Hillbilly()
{
    
}

void Hillbilly::Attack()
{
    //monsterData.mHP = monsterData.mHP - GetPlayer()->GetHp(); -> 임시 주석화
    cout << "전기톱 질주: 키이이이잉!";
    GetPlayer()->TakeDamage(monsterData.mATK);
}

