#include "ItemManager.h"

#include "ItemBase.h"
#include "ConsumableItem/ATKBuffPotion.h"
#include "ConsumableItem/HealingPotion.h"
#include "ConsumableItem/IConsumable.h"

ItemManager::ItemManager()
{
    ItemContainer.insert(make_pair(EItem::Chainsaw, new ItemBase("힐빌리 전기톱", 30)));
    ItemContainer.insert(make_pair(EItem::Berry, new ItemBase("베리", 5)));
    ItemContainer.insert(make_pair(EItem::Herb, new ItemBase("허브", 20)));
    ItemContainer.insert(make_pair(EItem::Water, new ItemBase("물", 10)));
    ItemContainer.insert(make_pair(EItem::GhoulSkin, new ItemBase("구울의 살점", 100)));
    ItemContainer.insert(make_pair(EItem::LichBone, new ItemBase("리치의 뼈", 300)));
    ItemContainer.insert(make_pair(EItem::HealingPotion, new HealingPotion("회복 포션", 10)));
    ItemContainer.insert(make_pair(EItem::ATKBuffPotion, new ATKBuffPotion("공격력 포션", 20)));
}

IConsumable* ItemManager::GetConsumableByID(EItem itemID)
{
    auto item = GetItemByID(itemID);
    return dynamic_cast<IConsumable*>(item);
}

ItemBase* ItemManager::GetItemByID(EItem itemID)
{
    auto it = ItemContainer.find(itemID);
    if (it != ItemContainer.end())
        return it->second;
    return nullptr;
}

std::string ItemManager::GetNameByID(EItem itemID)
{
    auto it = ItemContainer.find(itemID);
    if (it != ItemContainer.end())
        return ItemContainer[itemID]->GetName();
    return "";
}

ItemManager::~ItemManager()
{
    for (auto& pair : ItemContainer)
    {
        if (pair.second != nullptr)
        {
            delete pair.second;
            pair.second = nullptr; // 안전을 위해 nullptr 처리
        }
    }
    ItemContainer.clear();
}