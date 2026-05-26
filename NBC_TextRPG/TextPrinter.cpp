#include "TextPrinter.h"
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "Manager/PlayerManager.h"
#include "MultiConsole/ConsoleLogStream.h"

void TextPrinter::PrintText(ETextState state)
{
	switch (state)
	{
	case PlayerStat:
		
		int level = GetPlayer()->GetLevel();
		int hp = GetPlayer()->GetHp();
		int exp = GetPlayer()->GetExp();
		int gold = GetPlayer()->GetGold();
		int atk = GetPlayer()->GetATK();
		
		string stat = GetPlayer()->GetPlayerName() + " 레벨 : " + std::to_string(level) +"\n";
		
		stat += "경험치 : " + std::to_string(exp)+"\n"; 
		stat += "생명력 : " + std::to_string(hp)+"\n";
		stat += "공격력 : " + std::to_string(atk)+"\n";
		stat += "골드 : " + std::to_string(gold) + "\n";
		
		C_LOG(Stat)<<stat;
		break;
		
	}

}

void TextPrinter::ResetText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
    
	// 커서를 (0, 0) 위치로 슥 이동시킵니다.
	SetConsoleCursorPosition(hConsole, coord);
}
