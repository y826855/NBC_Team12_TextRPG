#include "Monster.h"
#include "Boss.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Boss::Boss(MonsterData monsterdata) : Monster( )
{
    this->monsterData.mName = monsterdata.mName;
    this->monsterData.exp = monsterdata.exp;
    this->monsterData.gold = monsterdata.gold;
    this->monsterData.dropItem = monsterdata.dropItem;
    cout << "\n\n*** 경고!! 담당 튜터 팍이 소환됩니다! ***";
    AsciiArt();
   this->SetBossStat();
 
}

Boss::~Boss()
{
    
}

void Boss::Attack()
{
    //monsterData.mHP = monsterData.mHP - GetPlayer()->GetHp(); -> 임시 주석화
    cout << "사랑의 뺨따귀: 철썩!\n" << endl;
    GetPlayer()->TakeDamage(mATK);
}

