#pragma once
#include "IConsumable.h"
#include "../ItemBase.h"

class ATKBuffPotion : public ItemBase, public IConsumable
{
    
public:
    ATKBuffPotion(string name, int price);
    void Use() override;

private:
    int Amount = 10;
};
