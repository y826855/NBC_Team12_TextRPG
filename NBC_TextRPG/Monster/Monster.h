#pragma once
#include <iostream>

using namespace std;

class Player;

class Monster 
{

public: 
    
    Monster(string mName, int mHP, int mATK);
    
    virtual ~Monster();
    
    virtual void Attack(Player* player) = 0;
    
    void TakeDamage(int damage);
    
    bool IsDeath();
    
    int GetExp();
    
    int GetHP();
    
    void SetStat(Player* player);
    
    
    //Item GetDropItem(); 이건 나중에 아이템 되면 생각하자
    
    //Item GetDropGold(); 이건 나중에 아이템 되면 생각하자
    
    //string GetName(); 이건 나중에 게임 로그 달 때 생각하자


protected:
    string mName;
    int mHP;
    int mATK;
    int exp;
    bool death;
    
    /*string itemName;
    int itemPrice;
    int gold;*/
    
    
    
    
    
};
