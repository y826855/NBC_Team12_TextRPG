#include "Player.h"
#include "TextPrinter.h"
#include <string>

void Player::AddExp(int exp)
{
	CurrentExp += exp;

	while (CurrentExp >= GoalExp)
	{
		LevelUp();
	}
}

int Player::GetExp()
{
	return CurrentExp;
}

int Player::GetLevel()
{
	return LV;
}

int Player::GetGold()
{
}

Player::Player()
{
	
}

void Player::LevelUp()
{
	CurrentExp -= GoalExp;
	LV += 1;
		
	Max_HP += LV * 20;
	HP = Max_HP;
	ATK += LV * 5;
	
	string levelup;
	levelup = "������ �ö����ϴ� ���� ���� : " + std::to_string(LV);

	Logger(levelup);
}
