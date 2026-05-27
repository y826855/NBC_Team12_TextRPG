#include "Monster.h"
#include "Ghoul.h"
#include "../Player.h"
#include "../Item/ItemManager.h"
#include "../Manager/PlayerManager.h"


Ghoul::Ghoul() : Monster()
{
    monsterData = {"구울", 0,0,25,15,EItem::GhoulSkin};
    SetStat();
    cout << "\n\033[30;43m구울의 울음소리...\033[0m";
    
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack()
{
    cout << "\033[30;43m카구네 휘두르기: 찰싹!\033[0m" << endl;
    GetPlayer()->TakeDamage(monsterData.mATK);
}

