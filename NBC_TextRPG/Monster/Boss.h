#pragma once
#include "Monster.h"

class Boss :Monster
{
public:
    Boss();
    ~Boss() override; 
    
    void Attack() override;
};