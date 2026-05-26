#pragma once


class Inventory;

class Shop
{
public:
    void OpenShop(Inventory* inventory);
    
private:
    void BuyItem(Inventory* inventory);
    
    void SellItem(Inventory* inventory);
};
