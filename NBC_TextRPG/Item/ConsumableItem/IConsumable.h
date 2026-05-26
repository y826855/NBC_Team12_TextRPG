#pragma once

#include <string>

using namespace std;

class IConsumable
{
public:
    virtual void Use() = 0;
};