#include "HealingPotion.h"

#include "../../Player.h"
#include "../../Manager/PlayerManager.h"
#include "../../MultiConsole/ConsoleLogStream.h"

HealingPotion::HealingPotion(string name, int price) : ItemBase(name, price)
{
    
}

void HealingPotion::Use()
{
    GetPlayer()->AddHp(Amount);
    
    C_LOG(EConsoleTag::UpperRight) << "체력 <<" << Amount << "회복" << endl;
}
