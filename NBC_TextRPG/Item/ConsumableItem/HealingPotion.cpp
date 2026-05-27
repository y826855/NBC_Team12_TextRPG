#include "HealingPotion.h"

#include <iostream>

#include "../../Player.h"
#include "../../Manager/PlayerManager.h"

HealingPotion::HealingPotion(string name, int price) : ItemBase(name, price)
{
    
}

void HealingPotion::Use()
{
    int healAmount = GetPlayer()->GetMaxHP() / 100.f * Amount;
    GetPlayer()->AddHp(min(1, healAmount));
    
    std::cout << "\n\n ====== 체력 10% (" << healAmount << ") 회복 ====== \n\n" << endl;
}
