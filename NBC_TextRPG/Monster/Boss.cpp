#include "Monster.h"
#include "Boss.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Boss::Boss() : Monster()
{
    monsterData = {"튜터팍", 0,0,100,100,EItem::Chainsaw};
    cout << "담당 튜터팍이 소환됩니다.";
    AsciiArt();
    SetBossStat();
 
}

Boss::~Boss()
{
    
}

void Boss::Attack()
{
    //monsterData.mHP = monsterData.mHP - GetPlayer()->GetHp(); -> 임시 주석화
    cout << "사랑의 뺨따귀: 철썩!";
    GetPlayer()->TakeDamage(monsterData.mATK);
}

