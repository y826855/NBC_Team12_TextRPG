#include "Shop.h"
#include <iostream>

#include "../Utility/InputHelper.h"

#include "Inventory.h"
#include "ItemManager.h"
#include "ItemBase.h"
#include "../Player.h"
#include "../Manager/PlayerManager.h"
#include "../MultiConsole/ConsoleController.h"
#include "../MultiConsole/ConsoleLogStream.h"

using namespace std;

Shop::Shop()
{
    WindowTag = EConsoleTag::UpperRight;

    ShopItemList = 
    {
        EItem::HealingPotion,
        EItem::ATKBuffPotion,
        EItem::Berry,
        EItem::Herb,
    };
}

void Shop::OpenShop() const
{
    while (true)
    {
        GetInventory()->ShowInventory();
        ConsoleController::GetInstance()->Clear(WindowTag);
        
        C_LOG(WindowTag)<< endl;
        C_LOG(WindowTag)<< "===== 상점 ====="<<endl;
        
        C_LOG(WindowTag)<< "1. 구매"<<endl;
        C_LOG(WindowTag)<< "2. 판매"<<endl;
        C_LOG(WindowTag)<< "3. 나가기"<<endl;
        
        int input = InputHelper::GetValidInput<int>(
            "선택 : ",1,3);
        
        switch (input)
        {
        case 1: BuyItem(); break;
        case 2: SellItem(); break;
        case 3:
            C_LOG(WindowTag)<<"상점을 떠납니다"<<endl;
            return;
        }
    }
}

void Shop::BuyItem() const
{
    ConsoleController::GetInstance()->Clear(WindowTag);
    
    C_LOG(WindowTag)<< endl;
    C_LOG(WindowTag)<< "===== 구매 ====="<<endl;

    for (int i = 0; i < ShopItemList.size(); i++)
    {
        auto item = ItemManager::GetInstance()->GetItemByID(ShopItemList[i]);
        ShowItemInfo(i + 1, item->GetName(), item->GetPrice());
    }

    int max = ShopItemList.size();
    int choice = InputHelper::GetValidInput<int>("구매할 아이템 선택 : ",1, max) - 1;
    EItem itemID = ShopItemList[choice];
    auto choicedItemPrice = ItemManager::GetInstance()->GetItemByID(ShopItemList[choice])->GetPrice();

    if (GetPlayer()->GetGold() < choicedItemPrice)
    {
        C_LOG(WindowTag) << "골드가 부족합니다.." << endl;
        return;
    }

    GetPlayer()->AddGold(choicedItemPrice);
    GetInventory()->AddItem(itemID,1);

    C_LOG(WindowTag) << "아이템 구매 완료!" << endl;
}

void Shop::SellItem() const
{
    ConsoleController::GetInstance()->Clear(WindowTag);
    
    auto inventory = GetInventory();
    if (inventory->IsEmpty())
    {
        C_LOG(WindowTag) << "인벤토리가 비어있습니다." << endl;    
        return;
    }
    
    C_LOG(WindowTag) << endl;
    C_LOG(WindowTag) << "===== 판매 =====" << endl;
    
    inventory->ShowInventory();
    C_LOG(WindowTag) << endl;
    
    auto items = inventory->GetAllItem();
    int i = 1;
    for (auto it : items)
    {
        auto item = ItemManager::GetInstance()->GetItemByID(it);
        C_LOG(WindowTag) << i++ << "." << item->GetName() << endl;
    }

    int choice = InputHelper::GetValidInput<int>("판매할 아이템 선택 : ",1,i) - 1;

    EItem itemID = items[choice];
    
    bool isRemoved = inventory->RemoveItem(itemID,1);
    
    if (!isRemoved)
    {
        C_LOG(WindowTag) << "아이템이 부족합니다." << endl;
        return;
    }
    
    int originPrice = ItemManager::GetInstance()->GetItemByID(itemID)->GetPrice();
    
    int sellPrice = static_cast<int>(originPrice * 0.6f);
    
    C_LOG(WindowTag) << sellPrice << " Gold 획득!" << endl;
    
}

void Shop::ShowItemInfo(int idx, string name, int gold) const
{
    C_LOG(WindowTag)<< idx <<". " << name << " : " << gold <<" Gold" <<endl;
}
