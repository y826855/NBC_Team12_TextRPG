#include "Shop.h"
#include <iostream>
#include <iomanip>  //출력정렬을 위해 사용

#include "../Utility/InputHelper.h"

#include "Inventory.h"
#include "ItemManager.h"
#include "ItemBase.h"
#include "../Player.h"
#include "../Manager/PlayerManager.h"
#include "../MultiConsole/ConsoleController.h"
#include "../MultiConsole/ConsoleLogStream.h"

//#include <windows.h>//테스트용

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
        
        ShowPlayerGold();
        
        
        C_LOG(WindowTag)<<R"(
        +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        +                                                                                   +
        +                        /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$                      +
        +                       /$$__  $$| $$  | $$ /$$__  $$| $$__  $$                     +
        +                      | $$  \__/| $$  | $$| $$  \ $$| $$  \ $$                     +
        +                      |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/                     +
        +                       \____  $$| $$__  $$| $$  | $$| $$____/                      +
        +                       /$$  \ $$| $$  | $$| $$  | $$| $$                           +
        +                      |  $$$$$$/| $$  | $$|  $$$$$$/| $$                           +
        +                       \______/ |__/  |__/ \______/ |__/                           +
        +                                                                                   +
        +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



          ============                       ============                      ============ 
            1. 구매                            2. 판매                           3. 나가기
          ============                       ============                      ============)";
        
        
        
        // C_LOG(WindowTag)<< endl;
        // C_LOG(WindowTag)<< "===== 상점 ====="<<endl;
        //
        // C_LOG(WindowTag)<< "1. 구매"<<endl;
        // C_LOG(WindowTag)<< "2. 판매"<<endl;
        // C_LOG(WindowTag)<< "3. 나가기"<<endl;
        
        int input = InputHelper::GetValidInput<int>(
            "선택 : ",1,3);

        ConsoleController::GetInstance()->Clear(WindowTag);
        ShowPlayerGold();
        
        switch (input)
        {
        case 1:
            {
                int buyResult = BuyItem();
                if (buyResult != 0) Sleep(500); 
                break;
            }
        case 2:
            {
                int sellResult = SellItem();
                if (sellResult != 0) Sleep(500);
                break;
            }
        case 3:
            C_LOG(WindowTag)<<"상점을 떠납니다"<<endl;
            Sleep(800);
            return;
        }
    }
}

int Shop::BuyItem() const
{
    C_LOG(WindowTag)<<"  0. 돌아가기";
    
    C_LOG(WindowTag)<< "===============================================< 구매 >===============================================";
    C_LOG(WindowTag)<< "======================================================================================================";
    C_LOG(WindowTag)<< "   No                                      아이템 이름                                  구매가격";
    C_LOG(WindowTag)<< "======================================================================================================\n";
    //C_LOG(WindowTag)<< "0. 돌아가기"<<endl;

    for (int i = 0; i < ShopItemList.size(); i++)
    {
        auto item = ItemManager::GetInstance()->GetItemByID(ShopItemList[i]);
        ShowItemInfo(i + 1, item->GetName(), item->GetPrice());
    }
    

    int max = ShopItemList.size();
    
    int choice = InputHelper::GetValidInput<int>("구매할 아이템 선택 : ",0, max );
    
    if (choice == 0)
    {
        return 0;
    }
    int choiceIdx = choice -1; 
    
    EItem itemID = ShopItemList[choiceIdx];
    auto choicedItemPrice = ItemManager::GetInstance()->GetItemByID(ShopItemList[choiceIdx])->GetPrice();

    if (GetPlayer()->GetGold() < choicedItemPrice)
    {
        C_LOG(WindowTag) << "골드가 부족합니다.." << endl;
        return choice;
    }

    GetPlayer()->AddGold(-choicedItemPrice);
    GetInventory()->AddItem(itemID,1);

    C_LOG(WindowTag) << "아이템 구매 완료!" << endl;
    return choice;
}

int Shop::SellItem() const 
{
    auto inventory = GetInventory();
    if (inventory->IsEmpty())
    {
        C_LOG(WindowTag) << "인벤토리가 비어있습니다." << endl;    
        return -1;
    }
    
    C_LOG(WindowTag) << "0. 돌아가기";
    
    C_LOG(WindowTag)<< "===============================================< 판매 >===============================================";
    C_LOG(WindowTag)<< "======================================================================================================";
    C_LOG(WindowTag)<< "   No                                      아이템 이름                                  판매가격";
    C_LOG(WindowTag)<< "======================================================================================================\n";
    //C_LOG(WindowTag) << endl;
    //C_LOG(WindowTag) << "===== 판매 =====" << endl;
    
    inventory->ShowInventory();
    
    auto items = inventory->GetAllItem();
    int i = 1;
    for (auto it : items)
    {
        auto item = ItemManager::GetInstance()->GetItemByID(it);
        // C_LOG(WindowTag) << i++ << "." << item->GetName()
        //     << "[ " << GetSellPrice(item->GetPrice()) << "G ]" << endl;
        
        C_LOG(WindowTag) << std::setw(4) << i++
                 << std::setw(47) << item->GetName()
                 << "\033[33m"
                 << std::setw(38) << GetSellPrice(item->GetPrice())
                 << " Gold"
                 << "\033[0m"
                 << endl;
    }
    
    
    

    int choice = InputHelper::GetValidInput<int>("판매할 아이템 선택 : ",0,i-1);
    if (choice == 0)
    {
        return 0;
    }
    int choiceIdx = choice - 1;
    EItem itemID = items[choiceIdx];
    
    bool isRemoved = inventory->RemoveItem(itemID,1);
    
    if (!isRemoved)
    {
        C_LOG(WindowTag) << "아이템이 부족합니다." << endl;
        return choice;
    }
    
    int originPrice = ItemManager::GetInstance()->GetItemByID(itemID)->GetPrice();
    
    int sellPrice = static_cast<int>(originPrice * 0.6f);

    GetPlayer()->AddGold(sellPrice);
    C_LOG(WindowTag) << "\033[33m"
                 << sellPrice << " Gold"
                 << "\033[0m"
                 << " 획득!" << endl;
    return choice;
}

void Shop::ShowPlayerGold() const
{
    C_LOG(WindowTag) << "\n\n\033[33m[ 보유 골드 : "
                 << GetPlayer()->GetGold()
                 << "G ]\033[0m\n";
}

void Shop::ShowItemInfo(int idx, string name, int gold) const
{
    //C_LOG(WindowTag)<< idx <<". " << name << " : " << gold <<" Gold" <<endl;
    C_LOG(WindowTag) << std::setw(4) << idx
                 << std::setw(47) << name
                 << "\033[33m"
                 << std::setw(38) << gold << " Gold"
                 << "\033[0m"
                 << "\n\n";
    
}

int Shop::GetSellPrice(int price) const
{
    return static_cast<int>(price * 0.6f);
}
