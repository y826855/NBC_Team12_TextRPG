#pragma once
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Item.h"



class BattleSystem
{

public:

Player*& player;   
Monster*& monster; 
Inventory& inventory;



BattleSystem(Player*& player, Monster*& monster);



void MonsterSpawn();


void BattleStart();


void ChoiceMenu();

};