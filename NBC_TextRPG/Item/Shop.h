#pragma once

class Player;
class Inventory;

class Shop
{
public:
    void OpenShop(Player* player, Inventory* inventory);
    
private:
    void BuyItem(Player* player, Inventory* inventory);
    
    void SellItem(Player* player, Inventory* inventory);
};
