#include "Monster.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"

Monster::Monster(MonsterData monsterData) 
{
    SetStat();
}

Monster::~Monster()
{
}

void Monster::TakeDamage()
{
    monsterData.mHP = monsterData.mHP - GetPlayer()->GetATK();
    
    if (monsterData.mHP <= 0)
    {
        monsterData.mHP = 0;
    }
    
    cout << GetPlayer()->GetATK() << " 만큼의 피해를 입었다!";
}

bool Monster::IsDeath()
{
    if (monsterData.mHP <=0)
    {
        death = true;
        cout << "몬스터 사망";
    }
    
    else
    {
        death = false;
    }
    return death;
}

int Monster::GetHP()
{
    return monsterData.mHP;
}

int Monster::GetExp()
{
    return monsterData.exp;
}

int Monster::GetDropGold()
{
    return monsterData.gold;
}

void Monster::SetStat()
{
    int randHP = rand() % 11 + 20; //랜덤 구현 -> 플레이어 레벨 x20~30중 무작위 (11가지 가짓수)
    int randATK = rand() % 6 + 5;  //랜덤 구현 -> 플레이어 레벨 x 5~10중 무작위 (6가지 가짓수)
    
    monsterData.mHP = GetPlayer()->GetLevel()*randHP; 
    monsterData.mATK = GetPlayer()->GetLevel()*randATK; 
}

void Monster::SetExp(int exp)
{
    monsterData.exp = exp;
}

void Monster::SetGold(int gold)
{
    monsterData.gold = gold;
}

void Monster::SetDropItem(EItem dropItem)
{
    int randValue = rand() % 100;
    if (randValue < 60)
    {
        monsterData.dropItem = dropItem;
    }
    else if (randValue < 30)
    {
        monsterData.dropItem = EItem::Berry;
    }    
    else if (randValue < 30)
    {
        monsterData.dropItem = EItem::Water;
    }
    else
    {
        monsterData.dropItem = EItem::Herb;
    }
}

EItem Monster::GetDropItem()
{
    return monsterData.dropItem;
}
