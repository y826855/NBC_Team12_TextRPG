#include "Player.h"
#include "TextPrinter.h"
#include <string>

void Player::GainExp(int exp)
{
	CurrentExp += exp;

	while (CurrentExp >= GoalExp)
	{
		LevelUp();
	}
}

int Player::GetLV()
{
	return LV;
}

void Player::LevelUp()
{
	CurrentExp -= GoalExp;
	LV += 1;
		
	Max_HP += LV * 20;
	HP = Max_HP;
	ATK += LV * 5;
	
	string levelup;
	levelup = "레벨이 올랐습니다 현재 레벨 : " + std::to_string(LV);

	Logger(levelup);
}
