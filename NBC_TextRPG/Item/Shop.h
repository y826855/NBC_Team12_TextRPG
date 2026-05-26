#pragma once
#include <vector>

#include "ItemManager.h"


enum class EConsoleTag;
class Inventory;

class Shop
{
public:
    Shop();
    void OpenShop() const;
    

private:
    void BuyItem() const;
    void SellItem() const;
    
    void ShowItemInfo(int idx, string name, int gold) const;

    EConsoleTag WindowTag;

    std::vector<EItem> ShopItemList;
};
