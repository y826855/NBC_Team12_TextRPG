#include "ATKBuffPotion.h"

#include <iostream>

#include "../../Player.h"
#include "../../Manager/PlayerManager.h"

ATKBuffPotion::ATKBuffPotion(string name, int price) : ItemBase(name, price)
{
}

void ATKBuffPotion::Use()
{
    GetPlayer()->AddATKBuff(Amount);

    std::cout << "\n\n ====== 공격력 증가 " << Amount << " ====== \n\n" << endl;  
}
