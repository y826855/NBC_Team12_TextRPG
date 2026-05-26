#pragma once
#include "Monster.h"

class Ghoul : public Monster
{
public:
    Ghoul(MonsterData monsterData);
    ~Ghoul() override; 
    
    void Attack() override;
    
};


