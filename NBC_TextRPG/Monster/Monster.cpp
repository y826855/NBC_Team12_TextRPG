#include "Monster.h"
#include  "Player.h" //(관련 오류 모두 Pull ReQuest 시 적용 될 예정)

Monster::Monster(MonsterData monsterData) 
{
    SetStat(player);
}

Monster::~Monster()
{
    
}

void Monster::TakeDamage(Player* player)
{
    monsterData.mHP = monsterData.mHP - player->GetATK();
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

void Monster::SetStat(Player* player)
{
    int randHP = rand() % 11 + 20;
    int randATK = rand() % 6 + 5;
    
    monsterData.mHP = player->GetLevel()*randHP; 
    monsterData.mATK = player->GetLevel()*randATK; 
}

void Monster::SetExp(int exp)
{
    monsterData.exp = exp;
}



