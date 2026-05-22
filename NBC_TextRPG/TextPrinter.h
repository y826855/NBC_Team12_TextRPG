#pragma once
#include "Utility/Singleton.h"
#define Logger(msg) TextPrinter::GetInstance()->PrintText(msg)
#include <string>
#include <iostream>

using namespace std;

class TextPrinter :public Singleton<TextPrinter>
{
    friend class Singleton<TextPrinter>;

private:
   //¿ÜºÎ ¼±¾ð ¿øÃµ ºÀ¼â
    TextPrinter() = default;
    ~TextPrinter() override = default;



public:
    void PrintText(string text);

private :

};

