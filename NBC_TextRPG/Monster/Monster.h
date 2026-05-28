#pragma once
#include <iostream>

using namespace std;

class Player;

enum class EItem;

//맴버변수를 구조체화하여 생성자 매개변수 간략화
struct MonsterData
{
    string mName;
    int exp;
    int gold;
    EItem dropItem;
    
    MonsterData() = default;
    
    MonsterData(string mName, int exp, int gold, EItem dropItem)
    {
        this->mName = mName;
        this->exp = exp;
        this->gold = gold;
        this->dropItem = dropItem;
    };
};


class Monster 
{

public: 
    
    Monster();
    
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
    int GetMaxHp();
    int GetATK();

protected:
    void SetStat();   
    
    void SetName(string name);
    
    void SetBossStat();
    
    void SetExp(int exp);
    
    void SetGold(int gold);
    
    void SetDropItem(EItem dropItem);
    
    int mHP;
    int Max_mHP;
    int mATK;
    
    MonsterData monsterData;
    bool death;
    
    //ToDo: 이것도 나중에 생각하자
    /*string itemName;
    int itemPrice;*/
    
};
