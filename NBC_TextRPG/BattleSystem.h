#pragma once
#include <string>
#include "Monster/Monster.h"
#include "Player.h"
class Monster;


class BattleSystem
{

public:

Player*& player;   
Monster*& monster; 



BattleSystem(Player*& player, Monster*& monster);



void MonsterSpawn();


void BattleStart();
    
    
void PlayerAttack();
    
    
void MonsterAttack();
    

void BattleReward();
    

void ItemReward();
    
    
void ChoiceMenu();

};