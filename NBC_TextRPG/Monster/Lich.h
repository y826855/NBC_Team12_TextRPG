#pragma once
#include "Monster.h"

class Lich : public Monster
{
public:
    Lich();
    ~Lich() override; 
    
    void Attack() override;
};


