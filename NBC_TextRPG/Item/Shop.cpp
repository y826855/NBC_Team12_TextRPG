#include "Shop.h"
#include <iostream>

#include "../Utility/InputHelper.h"

#include "Inventory.h"
#include "ItemManager.h"
#include "ItemBase.h"


using namespace std;

void Shop::OpenShop(Inventory* inventory)
{
    while (true)
    {
        cout<< endl;
        cout<< "===== 상점 ====="<<endl;
        
        cout<< "1. 구매"<<endl;
        cout<< "2. 판매"<<endl;
        cout<< "3. 나가기"<<endl;
        
        int input = InputHelper::GetValidInput<int>(
            "선택 : ",1,3);
        
        switch (input)
        {
        case 1:
            {
                BuyItem(inventory);
                break;
            }
        case 2:
            {
                SellItem(inventory);
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
void Shop::BuyItem(Inventory* inventory)
{
    cout<< endl;
    cout<< "===== 구매 ====="<<endl;
    
    cout<< "1. 힐빌리 전기톱 : "<<ItemManager::GetInstance()->GetItemByID(EItem::Chainsaw)
    ->GetPrice()<<" Gold"<<endl;
    
    cout<< "2. 구울의 살점 : "<<ItemManager::GetInstance()->GetItemByID(EItem::GhoulSkin)
    ->GetPrice()<<" Gold"<<endl;
    
    cout<< "3. 리치의 뼈 : "<<ItemManager::GetInstance()->GetItemByID(EItem::LichBone)
    ->GetPrice()<<" Gold"<<endl;
    
    cout<< "4. 베리 : "<<ItemManager::GetInstance()->GetItemByID(EItem::Berry)
    ->GetPrice()<<" Gold"<<endl;
    
    cout<< "5. 허브 : "<<ItemManager::GetInstance()->GetItemByID(EItem::Herb)
    ->GetPrice()<<" Gold"<<endl;
    
    cout<< "6. 물 : "<<ItemManager::GetInstance()->GetItemByID(EItem::Water)
    ->GetPrice()<<" Gold"<<endl;
    
    int choice = InputHelper::GetValidInput<int>("구매할 아이템 선택 : ",1,6);
    
    EItem itemID = EItem::None;
    
    switch (choice)
    {
    case 1:
        {
            itemID = EItem::Chainsaw;
            break;
        }
    case 2:
        {
            itemID = EItem::GhoulSkin;
            break;
        }
    case 3:
        {
            itemID = EItem::LichBone;
            break;
        }
    case 4:
        {
            itemID = EItem::Berry;
            break;
        }
    case 5:
        {
            itemID = EItem::Herb;
            break;
        }
    case 6:
        {
            itemID = EItem::Water;
            break;
        }
    }
    inventory->AddItem(itemID,1);
    
    cout<<"아이템 구매 완료!"<<endl;
}
void Shop::SellItem(Inventory* inventory)
{
    //판매할 물건 없으면 바로 퇴장, 혹은 입장 불가
    cout << endl;
    cout << "===== 판매 ====="<<endl;
    
    inventory->ShowInventory();
    cout<< endl;
    
    auto items = inventory->GetAllItem(); // Todo Vector로 받아오기
    int i = 0;
    for (auto it : items)
    {
        auto item = ItemManager::GetInstance()->GetItemByID(it);
        cout << i++ << "." << item->GetName() << endl;
    }

    int choice = InputHelper::GetValidInput<int>("판매할 아이템 선택 : ",0,i-1);
    
    EItem itemID = items[choice];
    
    bool isRemoved = inventory->RemoveItem(itemID,1);
    
    if (!isRemoved)
    {
        cout <<"아이템이 부족합니다."<<endl;
        return;
    }
    
    int originPrice = ItemManager::GetInstance()->GetItemByID(itemID)->GetPrice();
    
    int sellPrice = static_cast<int>(originPrice * 0.6f);
    
    cout << sellPrice << " Gold 획득!"<< endl;
    
}
