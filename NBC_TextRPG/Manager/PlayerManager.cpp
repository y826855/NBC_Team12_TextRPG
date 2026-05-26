#include "PlayerManager.h"
#include  "../Player.h"
#include "../Utility/InputHelper.h"

PlayerManager::PlayerManager()
{
    PlayerInstance =new Player();
}

Player* PlayerManager::GetPlayerInstance()
{
    return PlayerManager::PlayerInstance;
}

void PlayerManager::SetPlayerName()
{
    string name;
    string inputMessage = "플레이어의 이름을 입력해 주세요\n";
    name = InputHelper::GetValidName(inputMessage,2);
    GetPlayer()->SetName(name);
}
