#pragma once
#include "Monster.h"

class Boss :Monster
{
public:
    Boss(MonsterData monsterData);
    ~Boss() override; 
    
    void Attack() override;
};