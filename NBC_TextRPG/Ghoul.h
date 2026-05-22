#pragma once
#include "Monster/Monster.h"

class Ghoul :Monster
{
public:
    Ghoul(string mName, int mHP, int mATK);
    ~Ghoul() override; 
    
    void MAttack() override;
    
};


