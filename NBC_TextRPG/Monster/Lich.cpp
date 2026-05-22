#include "Monster.h"
#include "Lich.h"


Lich::Lich(MonsterData monsterData) : Monster(monsterData)
{
    cout << "리치 생성";
    SetExp(30);

}

Lich::~Lich()
{
}

void Lich::Attack(Player* player)
{
    cout << "지옥의 비행: 슈우우욱!";
}

