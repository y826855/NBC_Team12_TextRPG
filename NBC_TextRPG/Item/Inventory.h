#pragma once
#include <unordered_map>
#include <iostream>
#include "ItemBase.h"
#include "ItemManager.h"

using namespace std;

class Inventory {
private:
    std::unordered_map<EItem, int> ItemContainer;
    ItemManager* itemManager;
public:
    Inventory(ItemManager* itemManager);
    void AddItem(EItem itemID, int cout);
    bool RemoveItem(EItem itemID, int cout);
    int GetItemCount(EItem itemID);
    bool UseItem(EItem itemID);
    void ShowInventory();
};