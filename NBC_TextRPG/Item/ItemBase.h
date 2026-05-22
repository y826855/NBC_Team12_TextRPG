#pragma once
#include <string>

using namespace std;

enum class EItem
{
    None = 0,
    SlimeJelly = 1,
    Herb = 2,
    Water = 3,
    Berry = 4,
    OrcSkin = 5,
    DragonBone = 6,
};

class ItemBase
{
    string Name = "";
    int Price = 0;

public:
    ItemBase(string name, int price);

    string GetName();
    int GetPrice() const;
};
