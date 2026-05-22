#include "Monster.h"
#include "../Player.h"
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



