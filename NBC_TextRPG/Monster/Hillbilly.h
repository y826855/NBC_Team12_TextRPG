#pragma once
#include "Monster.h"

class Hillbilly : public Monster
{
public:
    Hillbilly(MonsterData monsterdata);
    ~Hillbilly() override; 
    
    void Attack() override;
};


