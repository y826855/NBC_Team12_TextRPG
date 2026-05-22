#include "Ghoul.h"

Ghoul::Ghoul(string mName, int mHP, int mATK) : Monster(mName, mHP, mATK)
{
    cout << "구울 생성";
}

Ghoul::~Ghoul()
{
}

void Ghoul::Attack()
{
    
    cout << "카구네 휘두르기!";
}

