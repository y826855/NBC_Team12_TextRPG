#pragma once
class Monster;
#include <string>
class Player
{
private :

	int Max_HP = 400;
	int HP = Max_HP;
	int CurrentExp = 0;
	int GoalExp = 100;
	int LV = 1;
	int ATK = 10;
	int Gold = 0;
    std::string PlayerName = " ";
	bool bisDead = false;
	
	
public:
	void AddExp(int exp);
	int GetExp();
	int GetLevel();
	int GetGold();
    int GetHp();
	int GetMaxHP();
	int GetATK();
	std::string GetPlayerName();
	void Attack(Monster* monster);
	bool IsDeath();
	void TakeDamage(int Damage);
	void SetName(std::string name);
	void AddGold(int gold);
	
	Player();
	
private :
	void LevelUp();
	
};

