#include "Inventory.h"
#include "ItemManager.h"

Inventory :: Inventory(ItemManager* itemManager)
{
    this->itemManager = itemManager;   
}
//아이템 획득
void Inventory :: AddItem(EItem itemID, int count)
{
    ItemContainer[itemID] += count;
    
    std::cout << itemManager->GetNameByID(itemID)
              << " " << count 
              <<"개 획득!"<< std::endl;
}
//아이템 사용
bool Inventory::UseItem(EItem itemID)
{
    auto it =ItemContainer.find(itemID);
    
    if (it == ItemContainer.end())
        return false;
    if (it ->second <=0)
        return false;
    
    it->second--;
    
    std::cout << ItemManager::GetInstance()->GetNameByID(itemID)
    << " 사용!"<<std::endl;
    
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
void Inventory::ShowInventory()
{
    std::cout<< std::endl;
    std::cout<<"===== Inventory ====="<< std::endl;
    
    for (auto& pair : ItemContainer)
    {
        std::cout<<"Name: "
        <<ItemManager::GetInstance()->GetNameByID(pair.first)
        <<std::endl;
        
        std::cout<< "Count: "
        <<pair.second<<std::endl;
    }
}