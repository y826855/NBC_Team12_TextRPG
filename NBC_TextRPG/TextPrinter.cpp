#include "TextPrinter.h"
#include <iostream>
#include <windows.h>

void TextPrinter::PrintText(string text)
{
	cout << text;

}

void TextPrinter::ResetText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
    
	// 커서를 (0, 0) 위치로 슥 이동시킵니다.
	SetConsoleCursorPosition(hConsole, coord);
}
