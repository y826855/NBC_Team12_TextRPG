#pragma once
#include "IConsumable.h"
#include "../ItemBase.h"

class HealingPotion : public ItemBase, public IConsumable 
{
    
public:
    HealingPotion(string name, int price);
    void Use() override;

private:
    int Amount = 10;
};
