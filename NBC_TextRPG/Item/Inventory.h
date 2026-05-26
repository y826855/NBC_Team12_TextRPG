#pragma once
#include <unordered_map>
#include "ItemManager.h"

using namespace std;

class Inventory {
private:
    std::unordered_map<EItem, int> ItemContainer;
public:
    void AddItem(EItem itemID, int cout);
    bool RemoveItem(EItem itemID, int cout);
    int GetItemCount(EItem itemID);
    bool UseItem(EItem itemID);
    void ShowInventory();
    std::vector<EItem> GetAllItem();
};