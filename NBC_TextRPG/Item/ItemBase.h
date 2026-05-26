#pragma once
#include <string>

using namespace std;

class ItemBase
{
    string Name = "";
    int Price = 0;

public:
    ItemBase(string name, int price);

    string GetName();
    int GetPrice() const;
};
