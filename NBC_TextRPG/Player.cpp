#include "Player.h"
#include "TextPrinter.h"
#include <algorithm>
#include <string>

#include "Monster/Monster.h"
#include "MultiConsole/ConsoleLogStream.h"
#include "Monster/MonsterManager.h"

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

void Player::AddHp(int Amount)
{
	HP += Amount;
	HP = std::min(HP, Max_HP);
	Logger(TextPrinter::PlayerStat);
}

int Player::GetHp()
{
	return HP;
}

int Player::GetMaxHP()
{
	return Max_HP;
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
	MonsterManager::GetInstance()->TakeDamage();
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
  
	Logger(TextPrinter::MonsterStat);
	
	cout << "[" << PlayerName << "] 공격받아 "
	 << "\033[31m" << Damage << "\033[0m"
	 << " 만큼의 피해를 입었다!\n";
	
	if (HP <= 0)
	{
		HP = 0;
		bisDead = true;
	}
	
}

void Player::SetName(std::string name)
{
	PlayerName = name;
	cout<<endl<<"환영합니다 " << PlayerName<<"님"<<endl;
}

void Player::ResetBuff()
{
	if (ATKBuff > 0)
		cout << " -----버프 효과 종료----- " << endl;
	
	ATKBuff = 0;
}

void Player::AddGold(int gold)
{
	this->Gold += gold;
}

void Player::AddATKBuff(int Amount)
{
	ATKBuff += Amount;
}


Player::Player()
{
	Max_HP = 200;
	HP = Max_HP;
	CurrentExp = 0;
	GoalExp = 100;
	LV = 1;
	ATK = 20;
	Gold = 0;
	ATKBuff = 0;
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
	Logger(TextPrinter::LevelUp);
	cout<<levelup<<"\n";
	
	Logger(TextPrinter::PlayerStat);
	
}


