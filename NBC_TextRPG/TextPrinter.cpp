#include "TextPrinter.h"
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "Manager/PlayerManager.h"

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
		
		string stat = GetPlayer()->GetPlayerName() + " 레벨 : " + std::to_string(level);
		
		stat += " 경험치 : " + std::to_string(exp); 
		stat += " 생명력 : " + std::to_string(hp);
		stat += " 공격력 : " + std::to_string(atk);
		stat += " 골드 : " + std::to_string(gold);
		
		cout<<stat;
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
