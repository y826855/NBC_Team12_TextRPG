#pragma once
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Item.h"



class BattleSystem
{

public:

Player*& player;   //플레이어
Monster*& monster;  //몬스터
bool ismenu = true;


BattleSystem(Player*& player, Monster*& monster);



void BattleStart();

};