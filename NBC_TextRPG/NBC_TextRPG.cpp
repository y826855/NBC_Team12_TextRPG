#include "MultiConsole/ConsoleController.h"
#include "Utility/InputHelper.h"
#include "Lobby.h"
#include "Item/Inventory.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (!ConsoleController::GetInstance()->Initialize(argc, argv))
    {
        return 0;
    }

    inv->AddItem(EItem::Berry, 5);
    inv->AddItem(EItem::Chainsaw, 5);
    inv->AddItem(EItem::Herb, 5);
    inv->AddItem(EItem::LichBone, 5);
    
    shop->OpenShop(inv);
    
    return 0;
}
