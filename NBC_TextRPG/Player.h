#pragma once
#include <string>
class Player
{
private :

	int Max_HP = 200;
	int HP = Max_HP;
	int CurrentExp = 0;
	int GoalExp = 100;
	int LV = 1;
	int ATK = 30;
	int Gold = 0;
    std::string PlayerName = " ";
	
public:
	void AddExp(int exp);
	int GetExp();
	int GetLevel();
	int GetGold();
    int GetHp();
	int GetATK();
	std::string GetPlayerName();
	
	Player();
	
private :
	void LevelUp();
};

