#pragma once
#include <iostream>

using namespace std;

class Player;

//맴버변수를 구조체화하여 생성자 매개변수 간략화
struct MonsterData
{
    string mName;
    int mHP;
    int mATK;
    int exp;
    int gold;
};


class Monster 
{

public: 
    
    Monster(MonsterData monsterData);
    
    virtual ~Monster();
    
    virtual void Attack() = 0;
    
    void TakeDamage();
    
    bool IsDeath();
    
    int GetExp();
    
    int GetHP();
    
    void SetStat();
    
    int GetDropGold();
    
    void SetGold(int gold);
    
    //ToDo: Item GetDropItem(); 이건 나중에 아이템 되면 생각하자
    
    //ToDo: string GetName(); 이건 나중에 게임 로그 달 때 생각하자

protected:
    void SetExp(int exp);
    
    MonsterData monsterData;
    bool death;
    
    //ToDo: 이것도 나중에 생각하자
    /*string itemName;
    int itemPrice;*/
    
};
