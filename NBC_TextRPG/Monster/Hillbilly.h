#pragma once
#include "Monster.h"

class Hillbilly : public Monster
{
public:
    Hillbilly();
    ~Hillbilly() override; 
    
    void Attack() override;
};


