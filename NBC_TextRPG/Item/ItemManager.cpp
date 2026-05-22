#include "ItemManager.h"

#include "ItemBase.h"

ItemManager::ItemManager()
{
    ItemContainer.insert(make_pair(EItem::SlimeJelly, new ItemBase("슬라임 젤리", 30)));
    ItemContainer.insert(make_pair(EItem::Berry, new ItemBase("베리", 5)));
    ItemContainer.insert(make_pair(EItem::Herb, new ItemBase("허브", 20)));
    ItemContainer.insert(make_pair(EItem::Water, new ItemBase("물", 10)));
    ItemContainer.insert(make_pair(EItem::OrcSkin, new ItemBase("오크가죽", 100)));
    ItemContainer.insert(make_pair(EItem::DragonBone, new ItemBase("드래곤의뼈", 300)));
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