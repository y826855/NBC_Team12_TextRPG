#pragma once
#include "Monster.h"

class Hillbilly :Monster
{
public:
    Hillbilly(MonsterData monsterData);
    ~Hillbilly() override; 
    
    void Attack() override;
};


