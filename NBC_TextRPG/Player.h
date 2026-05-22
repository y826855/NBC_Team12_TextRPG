#pragma once
class Player
{
private :

	int Max_HP = 200;
	int HP = Max_HP;
	int CurrentExp = 0;
	int GoalExp = 100;
	int LV = 1;
	int ATK = 30;

public:
	void GainExp(int exp);
	int GetLV();

private :
	void LevelUp();
};

