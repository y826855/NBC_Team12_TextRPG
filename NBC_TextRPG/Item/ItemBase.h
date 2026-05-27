#pragma once
#include <string>

class ItemBase
{
    std::string Name = "";
    int Price = 0;

public:
    ItemBase(std::string name, int price);
    virtual ~ItemBase() = default;

    std::string GetName();
    int GetPrice() const;
};
