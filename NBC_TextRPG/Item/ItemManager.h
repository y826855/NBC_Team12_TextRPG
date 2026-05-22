#pragma once

#include <string>
#include <unordered_map>

#include "../Utility/Singleton.h"

using namespace std;

enum class EItem;
class ItemBase;

class ItemManager : public Singleton<ItemManager>
{
    friend class Singleton<ItemManager>;

    unordered_map<EItem, ItemBase*> ItemContainer;

public:
    ItemManager();

    ItemBase* GetItemByID(EItem _itemID);
    string GetNameByID(EItem _itemID);

    ~ItemManager() override;
};
