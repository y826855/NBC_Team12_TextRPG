#pragma once

#include <string>
#include <unordered_map>

#include "../Utility/Singleton.h"

class IConsumable;
using namespace std;

enum class EItem
{
    None = 0,
    Chainsaw = 1,
    Herb = 2,
    Water = 3,
    Berry = 4,
    GhoulSkin = 5,
    LichBone = 6,
    HealingPotion = 7,
    ATKBuffPotion = 8,
};

class ItemBase;

class ItemManager : public Singleton<ItemManager>
{
    friend class Singleton<ItemManager>;

    unordered_map<EItem, ItemBase*> ItemContainer;

public:
    ItemManager();
    
    IConsumable* GetConsumableByID(EItem itemID);
    ItemBase* GetItemByID(EItem itemID);
    string GetNameByID(EItem itemID);

    ~ItemManager() override;
};
