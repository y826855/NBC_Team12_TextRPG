#include "Monster.h"
#include "Hillbilly.h"
#include "../Player.h"
#include "../Manager/PlayerManager.h"


Hillbilly::Hillbilly(MonsterData monsterData) : Monster(monsterData)
{
    cout << "힐빌리 생성";
    SetExp(50);

}

Hillbilly::~Hillbilly()
{
}

void Hillbilly::Attack()
{
    //monsterData.mHP = monsterData.mHP - GetPlayer()->GetHp(); -> 임시 주석화
    cout << "전기톱 질주: 키이이이잉!";
    GetPlayer()->TakeDamage(monsterData.mATK);
}

