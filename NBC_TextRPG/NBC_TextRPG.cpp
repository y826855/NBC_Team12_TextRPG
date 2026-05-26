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

    Lobby* lobby = new Lobby();
    
    lobby->Intro();
    lobby->ContentLoop();
    
    delete lobby;
    
    return 0;
}
