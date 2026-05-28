#pragma once
#include "Utility/Singleton.h"
#define Logger(msg) TextPrinter::GetInstance()->PrintText(msg)
#define Eraser() TextPrinter::GetInstance()->ResetText();
#include <string>
#include <iostream>

using namespace std;

class TextPrinter :public Singleton<TextPrinter>
{
    friend class Singleton<TextPrinter>;

public :
    enum ETextState
    {
       PlayerStat,
       MonsterStat,
       MonsterDie,
       LevelUp
    };
    
    
private:
   //외부 구현 금지
    TextPrinter() = default;
    ~TextPrinter() override = default;



public:
    void PrintText(ETextState state);
    void ResetText();
   
private :
    string MakeHpBar(int hp, int maxHp);
    string PadRight(const string& str, int width);
    string ShowTwoValue(int low, int high);
};

