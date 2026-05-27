#pragma once
class Monster;
#include <string>
class Player
{
private :

	int Max_HP = 200;
	int HP = Max_HP;
	int CurrentExp = 0;
	int GoalExp = 100;
	int LV = 1;
	int ATK = 20;
	int Gold = 0;

	int ATKBuff = 0;

	
    std::string PlayerName = " ";

	bool bisDead = false;

public:
	void AddExp(int exp);
	void AddHp(int Amount);
	void AddGold(int gold);
	void AddATKBuff(int Amount);
	
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
	void ResetBuff();

	Player();
	
private :
	void LevelUp();
	
};

