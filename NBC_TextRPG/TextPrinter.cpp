#include "TextPrinter.h"
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "Manager/PlayerManager.h"
#include "MultiConsole/ConsoleLogStream.h"
#include "MultiConsole/ConsoleController.h"

void TextPrinter::PrintText(ETextState state)
{
	ConsoleController::GetInstance()->Clear(EConsoleTag::UpperRight);
	
	switch (state)
	{
	case PlayerStat:
		
		int level = GetPlayer()->GetLevel();
		int hp = GetPlayer()->GetHp();
		int exp = GetPlayer()->GetExp();
		int gold = GetPlayer()->GetGold();
		int atk = GetPlayer()->GetATK();
		int maxHp = GetPlayer()->GetMaxHP();
		
		string stat ="\n";
		stat += "┌──────────────────────────┐\n";
		stat += "│      PLAYER STATUS       │\n";
		stat += "├──────────────────────────┤\n";

		stat += "│ " +
			PadRight("이름     : " + GetPlayer()->GetPlayerName(), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("레벨     : " + to_string(level), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("경험치   : " + to_string(exp), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("생명력   : " + to_string(hp), 25)
			+ "│\n";

		stat += "│ " +
			PadRight(
				"HP : " + MakeHpBar(hp, maxHp)
				+ " "
				,
				25
			)
			+ "│\n";

		stat += "│ " +
			PadRight("공격력   : " + to_string(atk), 25)
			+ "│\n";

		stat += "│ " +
			PadRight("골드     : " + to_string(gold) + " G", 25)
			+ "│\n";

		stat += "└──────────────────────────┘\n";

		
		C_LOG(UpperRight)<<stat;
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
