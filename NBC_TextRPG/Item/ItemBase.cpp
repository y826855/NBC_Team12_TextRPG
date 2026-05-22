#include "ItemBase.h"

ItemBase::ItemBase(string _name, int _price)
{
    Name = _name;
    Price = _price;
}

string ItemBase::GetName()
{
    return Name;
}

int ItemBase::GetPrice() const
{
    return Price;
}
