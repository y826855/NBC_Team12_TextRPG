#include "MonsterManager.h"

#include "Boss.h"
#include "Ghoul.h"
#include "Hillbilly.h"
#include "Lich.h"
#include <random>
#include "../Item/Inventory.h"
#include "../Manager/PlayerManager.h"
#include "../Player.h"
#include "../TextPrinter.h"

MonsterManager::MonsterManager()
{
    MonsterDataContainer.insert(make_pair(EMonster::Ghoul, MonsterData("구울", 25,15,EItem::GhoulSkin)));
    MonsterDataContainer.insert(make_pair(EMonster::Hillbilly, MonsterData("힐빌리", 30,30,EItem::Chainsaw)));
    MonsterDataContainer.insert(make_pair(EMonster::Lich, MonsterData("리치", 50,50,EItem::LichBone)));
    MonsterDataContainer.insert(make_pair(EMonster::Boss, MonsterData("튜터팍", 100,100,EItem::Chainsaw)));
}

MonsterManager::~MonsterManager()
{
   CurrentMonster.reset();
 
}

int MonsterManager::GetRandom(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void MonsterManager::BattleReward()
{
    GetPlayer()->AddExp(CurrentMonster->GetExp());
    GetPlayer()->AddGold(CurrentMonster->GetDropGold());
    
    Inventory::GetInstance()->AddItem(CurrentMonster->GetDropItem(), 1);
}


void MonsterManager::TakeDamage()
{
    CurrentMonster->TakeDamage();
    if (CurrentMonster->IsDeath())
    {
        BattleReward();
    }
    else
    {
        Logger(TextPrinter::MonsterStat);
    }
}

bool MonsterManager::IsDeath()
{
   return CurrentMonster->IsDeath();
}

int MonsterManager::GetExp()
{
    return CurrentMonster->GetExp();
}

int MonsterManager::GetHP()
{
    return CurrentMonster->GetHP();
}

int MonsterManager::GetDropGold()
{
    return CurrentMonster->GetDropGold();
}

EItem MonsterManager::GetDropItem()
{
    return CurrentMonster->GetDropItem();   
}

void MonsterManager::AsciiArt()
{
    
}

string MonsterManager::GetName()
{
    return CurrentMonster->GetName();
}

int MonsterManager::GetMaxHp()
{
    return CurrentMonster->GetMaxHp();
}

MonsterData MonsterManager::GetMonsterDataByID(EMonster monsterID)
{
    auto it = MonsterDataContainer.find(monsterID);
    if (it != MonsterDataContainer.end())
        return it->second;
    return MonsterDataContainer.find(EMonster::Ghoul)->second;
}

void MonsterManager::MonsterAttack()
{
    CurrentMonster->Attack();
}


void MonsterManager::MonsterSpawn()
{
  
    CurrentMonster.reset();
    if ( CurrentMonster != nullptr) return;
    int MonsterNumber = GetRandom(1, 3);

    switch (MonsterNumber)
    {
    case 1:
        {
            MonsterData monster_data = GetMonsterDataByID(EMonster::Ghoul);
            CurrentMonster =  std::make_unique<Ghoul>(monster_data);     
            break;
        }
    case 2:
        {
            MonsterData monster_data = GetMonsterDataByID(EMonster::Hillbilly);
            CurrentMonster =  std::make_unique<Hillbilly>(monster_data);     
            break;
        }
    case 3:
        {
            MonsterData monster_data = GetMonsterDataByID(EMonster::Lich);
            CurrentMonster =  std::make_unique<Lich>(monster_data);     
            break;
        }
    }
    
    Logger(TextPrinter::MonsterStat);
}

void MonsterManager::BossSpawn()
{
    MonsterData monster_data = GetMonsterDataByID(EMonster::Boss);
    CurrentMonster =  std::make_unique<Boss>(monster_data);     
}

int MonsterManager::GetATK()
{
    return CurrentMonster->GetATK();
}
