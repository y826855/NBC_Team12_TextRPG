#include "ItemBase.h"

ItemBase::ItemBase(string name, int price)
{
    Name = name;
    Price = price;
}

string ItemBase::GetName()
{
    return Name;
}

int ItemBase::GetPrice() const
{
    return Price;
}
