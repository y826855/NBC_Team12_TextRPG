#include "TextPrinter.h"
#include <iostream>

#include <windows.h>

#include "Player.h"
#include "Manager/PlayerManager.h"
#include "Monster/MonsterManager.h"
#include "MultiConsole/ConsoleController.h"
#include "MultiConsole/ConsoleLogStream.h"
#include "MultiConsole/ConsoleController.h"

void TextPrinter::PrintText(ETextState state)
{
	ConsoleController::GetInstance()->Clear(EConsoleTag::UpperRight);
	
	string stat ="\n";
	switch (state)
	{
	case PlayerStat:
		
		stat += "┌──────────────────────────┐\n";
		stat += "│      PLAYER STATUS       │\n";
		stat += "├──────────────────────────┤\n";

		stat += "│ " +
			PadRight("이름     : " + GetPlayer()->GetPlayerName(), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("레벨     : " + to_string(GetPlayer()->GetLevel()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("경험치   : " + to_string(GetPlayer()->GetExp()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("생명력   : " + to_string(GetPlayer()->GetHp()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight(
				"체력바 : " + MakeHpBar(GetPlayer()->GetHp(), GetPlayer()->GetMaxHP())
				+ " "
				,
				25
			)
			+ "│\n";

		stat += "│ " +
			PadRight("공격력   : " + to_string(GetPlayer()->GetATK()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("골드     : " + to_string(GetPlayer()->GetGold()) + " G", 25)
			+ "│\n";

		stat += "└──────────────────────────┘\n";

		
		C_LOG(EConsoleTag::UpperRight)<<stat;
		break;
		
	case LevelUp:
		
		Beep(523, 150);
		Beep(659, 150);
		Beep(784, 150);
		Beep(1046, 400);
		
		for (int i = 0; i < 6; ++i) // 0.5초 * 6 = 3초
		{
			string box = "\n";

			box += "+------------------------+\n";

			if (i % 2 == 0)
				box += "|        LEVEL UP        |\n";
			else
				box += "|                        |\n";

			box += "+------------------------+\n";

			ConsoleController::GetInstance()->Clear(EConsoleTag::UpperRight);
			C_LOG(EConsoleTag::UpperRight) << box;

			Sleep(100);
		}
		ConsoleController::GetInstance()->Clear(EConsoleTag::UpperRight);
		stat += "┌──────────────────────────┐\n";
		stat += "│      PLAYER STATUS       │\n";
		stat += "├──────────────────────────┤\n";

		stat += "│ " +
			PadRight("이름  : " + GetPlayer()->GetPlayerName(), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("레벨  : " + to_string(GetPlayer()->GetLevel()-1) + " -> "  + to_string(GetPlayer()->GetLevel()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("경험치 : " + to_string(GetPlayer()->GetExp()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("생명력 : " +to_string(GetPlayer()->GetHp()-GetPlayer()->GetLevel() * 20)+" -> " + to_string(GetPlayer()->GetHp()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight(
				"체력바 : " + MakeHpBar(GetPlayer()->GetHp(), GetPlayer()->GetMaxHP())
				+ " "
				,
				25
			)
			+ "│\n";

		stat += "│ " +
			PadRight("공격력 : " +to_string(GetPlayer()->GetATK() - GetPlayer()->GetLevel()*5) +" -> " + to_string(GetPlayer()->GetATK()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("골드     : " + to_string(GetPlayer()->GetGold()) + " G", 25)
			+ "│\n";

		stat += "└──────────────────────────┘\n";
		
		C_LOG(EConsoleTag::UpperRight)<<stat;
		Sleep(1000);
		break;
		
	case MonsterStat:
		PrintText(PlayerStat);
		stat += "┌──────────────────────────┐\n";
		stat += "│      MONSTER STATUS      │\n";
		stat += "├──────────────────────────┤\n";

		stat += "│ " +
			PadRight("이름  : " + MonsterManager::GetInstance()->GetName(), 25)
			+ "│\n";
		

		stat += "│ " +
			PadRight("생명력 : " +to_string(MonsterManager::GetInstance()->GetHP()), 25)
			+ "│\n";

		stat += "│ " +
			PadRight(
				"체력바 : " + MakeHpBar(MonsterManager::GetInstance()->GetHP(), MonsterManager::GetInstance()->GetMaxHp())
				+ " "
				,
				25
			)
			+ "│\n";

		stat += "│ " +
			PadRight("공격력 : " +to_string(MonsterManager::GetInstance()->GetATK()), 25)
			+ "│\n";

		
		stat += "└──────────────────────────┘\n";
		C_LOG(EConsoleTag::UpperRight)<<stat;
		break;
	}

}

void TextPrinter::ResetText()
{
	ConsoleController::GetInstance()->Clear(EConsoleTag::UpperRight);
}

string TextPrinter::MakeHpBar(int hp, int maxHp)
{
	int barCount = 16;

	int filled =
		(hp * barCount) / maxHp;

	string bar = "[";

	for (int i = 0; i < barCount; i++)
	{
		if (i < filled)
			bar += "#";
		else
			bar += "-";
	}

	bar += "]";

	return bar;
	
}

string TextPrinter::PadRight(const string& str, int width)
{
	if (str.length() >= width)
		return str;

	return str + string(width - str.length(), ' ');
}


