#pragma once
#include "Monster.h"

class Lich : public Monster
{
public:
    Lich(MonsterData monsterData);
    ~Lich() override; 
    
    void Attack() override;
};


