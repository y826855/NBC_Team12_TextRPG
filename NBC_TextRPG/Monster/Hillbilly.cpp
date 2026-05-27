#include "Monster.h"
#include "Hillbilly.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Hillbilly::Hillbilly() : Monster()
{
    monsterData = {"힐빌리", 0,0,30,30,EItem::Chainsaw};
    SetStat();
    cout << "\n\033[30;43m힐빌리의 전기톱 소리가 들린다...\033[0m";
}

Hillbilly::~Hillbilly()
{
    
}

void Hillbilly::Attack()
{
    //monsterData.mHP = monsterData.mHP - GetPlayer()->GetHp(); -> 임시 주석화
    cout << "\033[30;43m전기톱 질주: 키이이이잉!\033[0m" << endl;
    GetPlayer()->TakeDamage(monsterData.mATK);
}

