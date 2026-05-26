#include "ATKBuffPotion.h"

#include "../../Player.h"
#include "../../Manager/PlayerManager.h"
#include "../../MultiConsole/ConsoleLogStream.h"

ATKBuffPotion::ATKBuffPotion(string name, int price) : ItemBase(name, price)
{
}

void ATKBuffPotion::Use()
{
    GetPlayer()->AddATKBuff(Amount);

    C_LOG(EConsoleTag::UpperRight) << "공격력 증가 " << Amount << endl;  
}
