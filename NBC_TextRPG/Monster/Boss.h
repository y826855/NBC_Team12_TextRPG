#pragma once
#include "Monster.h"

class Boss :public Monster
{
public:
    Boss();
    ~Boss() override; 
    
    void Attack() override;
};