#include "ItemManager.h"
#include "ItemBase.h"
#include "ConsumableItem/ATKBuffPotion.h"
#include "ConsumableItem/HealingPotion.h"
#include "ConsumableItem/IConsumable.h"

ItemManager::ItemManager()
{
    ItemContainer[EItem::Chainsaw] = std::make_unique<ItemBase>("힐빌리 전기톱", 30);
    ItemContainer[EItem::Berry] = std::make_unique<ItemBase>("베리", 5);
    ItemContainer[EItem::Herb] = std::make_unique<ItemBase>("허브", 20);
    ItemContainer[EItem::Water] = std::make_unique<ItemBase>("물", 10);
    ItemContainer[EItem::GhoulSkin] = std::make_unique<ItemBase>("구울의 살점", 100);
    ItemContainer[EItem::LichBone] = std::make_unique<ItemBase>("리치의 뼈", 300);
    ItemContainer[EItem::HealingPotion] = std::make_unique<HealingPotion>("회복 포션", 10);
    ItemContainer[EItem::ATKBuffPotion] = std::make_unique<ATKBuffPotion>("공격력 포션", 20);
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
        return it->second.get(); // unique_ptr 내부의 포인터를 반환
    return nullptr;
}

std::string ItemManager::GetNameByID(EItem itemID)
{
    auto it = ItemContainer.find(itemID);
    if (it != ItemContainer.end())
        return it->second->GetName();
    return "";
}
