#include "PlayerManager.h"
#include  "../Player.h"

PlayerManager::PlayerManager()
{
    PlayerInstance =new Player();
}

Player* PlayerManager::GetPlayerInstance()
{
    return PlayerManager::PlayerInstance;
}
