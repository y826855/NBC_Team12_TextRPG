#pragma once
#include "Monster.h"

class Lich :Monster
{
public:
    Lich(MonsterData monsterData);
    ~Lich() override; 
    
    void Attack(Player* player) override;
};


