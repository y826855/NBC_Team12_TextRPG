#pragma once
#include  "../Utility/Singleton.h"
#include <memory>
#include  "../Item/ItemManager.h"
#include <unordered_map>

#include "Monster.h"


class Monster;


using namespace std;

class MonsterManager : public Singleton<MonsterManager>
{
   public: friend class Singleton<MonsterManager>;
    

   
public:
   enum class EMonster
   {
      None = 0,
      Ghoul = 1,
      Hillbilly =2,
      Lich =3,
      Boss = 4
   };
   
   
private :
   
   unique_ptr<Monster> CurrentMonster;
   unordered_map<EMonster, MonsterData> MonsterDataContainer;
   MonsterData  GetMonsterDataByID(EMonster monsterID);
  
public :
 
   void MonsterAttack();
   
   void TakeDamage();
    
   bool IsDeath();
    
   int GetExp();
    
   int GetHP();
    
   int GetDropGold();
    
   EItem GetDropItem();
    
   void AsciiArt();
    
   string GetName();
   
   int GetMaxHp();
   
   MonsterManager();
   void MonsterSpawn();
   void BossSpawn();
   
   int GetATK();
   
   ~MonsterManager();
   
private :
   
   int GetRandom(int min, int max);
   void BattleReward();
   
};
