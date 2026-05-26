#pragma once
#include "Monster.h"

class Hillbilly : public Monster
{
public:
    Hillbilly(MonsterData monsterData);
    ~Hillbilly() override; 
    
    void Attack() override;
};


