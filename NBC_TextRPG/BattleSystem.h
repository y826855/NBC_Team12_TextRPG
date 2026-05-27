#pragma once
#include "Monster/Monster.h"

class Monster;

class BattleSystem
{
    Player* player;   
    Monster* monster;
    
    bool isBossSpawn=false;
    bool isClear=false;
    bool bIsGameOver=false;
    
public:
    
    BattleSystem();
    int GetRandom(int min, int max);

    void BattleStart();

    bool IsGameOver();
    void PlayerDie();
    void EndTurnPhase();

private:
    void MonsterSpawn();

    void NormalBattleLoop();
    
    void BossBattleLoop();
    
    void BattleReward();
    
    void ItemReward();

    void BossCheck();
    
    void InitConsole();
    
    //void ChoiceMenu();
};