#pragma once
#include "Monster.h"

class Lich : public Monster
{
public:
    Lich(MonsterData monsterdata);
    ~Lich() override; 
    
    void Attack() override;
};


