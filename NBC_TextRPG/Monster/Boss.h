#pragma once
#include "Monster.h"

class Boss :public Monster
{
public:
    Boss(MonsterData monsterdata);
    ~Boss() override; 
    
    void Attack() override;
};