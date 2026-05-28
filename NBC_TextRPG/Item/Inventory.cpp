#include "Inventory.h"

#include <iostream>

#include "ItemBase.h"
#include "ItemManager.h"
#include "../MultiConsole/ConsoleController.h"
#include "../Utility/InputHelper.h"
#include "ConsumableItem/IConsumable.h"


Inventory::Inventory()
{
    WindowTag = EConsoleTag::LowerRight;
}

//아이템 획득
void Inventory::AddItem(EItem itemID)
{
    AddItem(itemID, 1);
}

void Inventory::AddItem(EItem itemID, int count)
{
    ItemContainer[itemID] += count;

    C_LOG(WindowTag) << " * " << ItemManager::GetInstance()->GetNameByID(itemID)
        + " " + std::to_string(count) +"개 획득!\n" << endl;
}

//아이템 사용
bool Inventory::UseItem(EItem itemID)
{
    auto it =ItemContainer.find(itemID);
    
    if (it == ItemContainer.end())
        return false;
    if (it ->second <=0)
        return false;
    
    auto item = ItemManager::GetInstance()->GetConsumableByID(itemID);
    if (item == nullptr)
        return false;

    item->Use(); 
    it->second--;
    if (it->second <= 0)
        ItemContainer.erase(it);
    
    return true;
}

//아이템 삭제
bool Inventory::RemoveItem(EItem itemID, int count)
{
    auto it = ItemContainer.find(itemID);
    
    if (it == ItemContainer.end())
        return false;
    if (it->second < count)
        return false;
    it->second -=count;

    if (it->second <= 0)
        ItemContainer.erase(it);
    
    return true;
}

//아이템 개수 반환
int Inventory::GetItemCount(EItem itemID)
{
    auto it = ItemContainer.find(itemID);
    
    if (it != ItemContainer.end())
        return it->second;
    
    return 0;
}

//인벤토리 출력
void Inventory::ShowInventory() const
{
    ConsoleController::GetInstance()->Clear(WindowTag);
    
    C_LOG(WindowTag)<< endl;
    C_LOG(WindowTag)<<"===== Inventory ====="<< endl;
    
    for (auto& pair : ItemContainer)
    {
        ShowItemInfo(pair);
    }
}

bool Inventory::UseItemInBattlePhase()
{
    ConsoleController::GetInstance()->Clear(WindowTag);
    
    vector<EItem> consumableItems;
    for (auto item : ItemContainer)
    {
        if (item.second > 0 && ItemManager::GetInstance()->GetConsumableByID(item.first))
            consumableItems.push_back(item.first);
    }

    if (consumableItems.empty())
    {
        C_LOG(WindowTag) << "\n사용 가능한 아이템 없음\n" << endl;
        return false;
    }

    C_LOG(WindowTag) << "\n=======아이템 사용=======\n"; 
    auto PrintConsumableList = [this, &consumableItems]() {
        int index = 1;
        for (auto consumable : consumableItems)
        {
            if (GetItemCount(consumable) <= 0) continue;
            C_LOG(WindowTag) << "[" <<index++ << "] " 
                << ItemManager::GetInstance()->GetNameByID(consumable)
                << "      [ 보유 갯수: " << ItemContainer[consumable] << " ]" << endl;
        }
    };

    PrintConsumableList();
    int max = consumableItems.size();
    int choice = InputHelper::GetValidInput("\n\n사용 아이템 입력 : ", 1, max) - 1;
    
    UseItem(consumableItems[choice]);
    ConsoleController::GetInstance()->Clear(WindowTag);
    PrintConsumableList();

    Sleep(500);
    
    return true;
}


std::vector<EItem> Inventory::GetAllItem() const
{
    std::vector<EItem> Items;
    Items.reserve(ItemContainer.size());
    
    for (const auto& Pair : ItemContainer)
    {
        Items.push_back(Pair.first);
    }
    
    return Items;
}

bool Inventory::IsEmpty() const
{
    return ItemContainer.empty();
}

void Inventory::ShowItemInfo(const pair<EItem, int>& item) const
{
    C_LOG(WindowTag) << " - " << ItemManager::GetInstance()->GetNameByID(item.first)
        << "[ 보유 갯수: " << item.second << " ]" << endl;
}

void Inventory::ShowItemInfo(EItem itemID)
{
    auto it = ItemContainer.find(itemID);
    if (it == ItemContainer.end())
        return;
    ShowItemInfo(*it);
}
