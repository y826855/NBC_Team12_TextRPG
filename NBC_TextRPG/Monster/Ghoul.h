#pragma once
#include "Monster.h"

class Ghoul :Monster
{
public:
    Ghoul(MonsterData monsterData);
    ~Ghoul() override; 
    
    void Attack() override;
    
};


