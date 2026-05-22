#include "Monster.h"
#include  "Player.h"

Monster::Monster(string mName, int mHP, int mATK) 
: mName(mName), mHP(mHP), mATK(mATK)
{
    SetStat(player);
}

Monster::~Monster()
{
    
}


void Monster::TakeDamage(int damage)
{
    
}


bool Monster::IsDeath()
{
    if (mHP <=0)
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
    return mHP;
}



void Monster::SetStat(Player* player)
{
    int randHP = rand() % 11 + 20;
    int randATK = rand() % 6 + 5;
    
    mHP = player->GetLevel()*randHP; //함수 구현 예정
    mATK = player->GetLevel()*randATK; //함수 구현 예정
}

