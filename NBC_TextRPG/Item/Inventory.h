#pragma once
#include <unordered_map>
#include <vector>

#include "ItemManager.h"
#include "../Utility/Singleton.h"

#define GetInventory Inventory::GetInstance

enum class EConsoleTag;

class Inventory : public Singleton<Inventory>
{
private:
    std::unordered_map<EItem, int> ItemContainer;
   
public:
    Inventory();
    
    void AddItem(EItem itemID);
    void AddItem(EItem itemID, int cout);
    bool RemoveItem(EItem itemID, int cout);
    int GetItemCount(EItem itemID);
    bool UseItem(EItem itemID);
    
    void ShowInventory() const;
    void UseItemInBattlePhase();
    std::vector<EItem> GetAllItem() const;
    bool IsEmpty() const;

private:
    void ShowItemInfo(const pair<EItem, int>& item) const;
    void ShowItemInfo(EItem itemID);
    
    EConsoleTag WindowTag;
};
