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
    int BuyItem() const;
    int SellItem() const;

    void ShowPlayerGold() const;
    void ShowItemInfo(int idx, string name, int gold) const;

    int GetSellPrice(int price) const;

    EConsoleTag WindowTag;

    std::vector<EItem> ShopItemList;
};
