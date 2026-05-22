#include "Player.h"
#include "TextPrinter.h"
#include <string>

#include "Monster/Monster.h"

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
	 return Gold;
}

int Player::GetHp()
{
	return HP;
}

int Player::GetATK()
{
	return ATK;
}

std::string Player::GetPlayerName()
{
	return PlayerName;
}

void Player::Attack()
{
	CurrentMonster->TakeDamage();
}

bool Player::IsDeath()
{
	return bisDead;
}

void Player::TakeDamage(int Damage)
{
	if (bisDead)
	{
		HP = 0;
		return;
	}
	HP -= Damage;
	if (HP <= 0)
	{
		HP = 0;
		bisDead = true;
	}
	
}

void Player::SetCurrentMonster(Monster* Monster)
{
	CurrentMonster = Monster;
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
	levelup = "레벨이 올랐습니다 현재 레벨: " + std::to_string(LV);

	cout<<levelup<<"\n";
	Logger(TextPrinter::PlayerStat);
}
