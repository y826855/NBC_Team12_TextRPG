#include "Shop.h"
#include <iostream>

#include "Inventory.h"
#include "ItemManager.h"

#include "../Player.h"
#include "../Utility/InputHelper.h"

using namespace std;

void Shop::OpenShop(Player* player, Inventory* inventory)
{
    while (true)
    {
        cout<< endl;
        cout<< "===== 상점 ====="<<endl;
        cout<< "Gold : "<<player->GetGold()<<endl;
        
        cout<< "1. 구매"<<endl;
        cout<< "2. 판매"<<endl;
        cout<< "3. 나가기"<<endl;
        
        int input = InputHelper::GetValidInput<int>(
            "선택 : ",1,3);
        
        switch (input)
        {
        case 1:
            {
                BuyItem(player, inventory);
                break;
            }
        case 2:
            {
                SellItem(player, inventory);
                break;
            }
        case 3:
            {
                cout<<"상점을 떠납니다"<<endl;
                return;
            }
        }
    }
}
void Shop::BuyItem(Player* player, Inventory* inventory)
{
    cout<< endl;
    cout<< "===== 구매 ====="<<endl;
}

void Shop::SellItem(Player* player, Inventory* inventory)
{
}
