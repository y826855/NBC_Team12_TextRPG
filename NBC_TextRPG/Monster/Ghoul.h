#pragma once
#include "Monster.h"

class Ghoul : public Monster
{
public:
    Ghoul(MonsterData monsterdata);
    ~Ghoul() override; 
    
    void Attack() override;
    
};


