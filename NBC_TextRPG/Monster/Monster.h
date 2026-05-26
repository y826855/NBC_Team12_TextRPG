#pragma once
#include <iostream>

using namespace std;

class Player;

enum class EItem;

//맴버변수를 구조체화하여 생성자 매개변수 간략화
struct MonsterData
{
    string mName;
    int mHP;
    int mATK;
    int exp;
    int gold;
    EItem dropItem;
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
    
    int GetDropGold();
    
    EItem GetDropItem();
    
    void AsciiArt();
    
    string GetName();

protected:
    void SetStat();
    
    void SetBossStat();
    
    void SetExp(int exp);
    
    void SetGold(int gold);
    
    void SetDropItem(EItem dropItem);
    
    MonsterData monsterData;
    bool death;
    
    //ToDo: 이것도 나중에 생각하자
    /*string itemName;
    int itemPrice;*/
    
};
