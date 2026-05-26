#pragma once
#include "Monster.h"

class Ghoul : public Monster
{
public:
    Ghoul();
    ~Ghoul() override; 
    
    void Attack() override;
    
};


