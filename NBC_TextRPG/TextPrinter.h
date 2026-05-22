#pragma once
#include "Utility/Singleton.h"
#define Logger(msg) TextPrinter::GetInstance()->PrintText(msg)
#define Eraser() TextPrinter::GetInstancce()->ResetText();
#include <string>
#include <iostream>

using namespace std;

class TextPrinter :public Singleton<TextPrinter>
{
    friend class Singleton<TextPrinter>;

public :
    enum ETextState
    {
       PlayerStat
    };
    
    
private:
   //외부 구현 금지
    TextPrinter() = default;
    ~TextPrinter() override = default;



public:
    void PrintText(ETextState state);
    void ResetText();

private :

};

