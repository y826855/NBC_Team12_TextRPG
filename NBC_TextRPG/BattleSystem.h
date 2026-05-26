#pragma once
#include <string>
#include "Monster/Monster.h"
#include "Player.h"
#include "Utility/InputHelper.h"

class Monster;



class BattleSystem
{

public:

Player*& player;   
Monster*& monster;
    
    
bool isBossSpawn=false;
bool isClear=false;



BattleSystem(Player*& player, Monster*& monster);



void MonsterSpawn();


void BattleStart();
    
    
    
void BattleReward();
    
    
void ItemReward();


void BossCheck();
    
    
void ChoiceMenu();

};