#pragma once

#include "../Utility/Singleton.h"
#define GetPlayer() PlayerManager::GetInstance()->GetPlayerInstance()
#define SetNameByInput() PlayerManager::GetInstance()->SetPlayerName();

class Player;


class PlayerManager : public Singleton<PlayerManager>
{
  
private:
  Player* PlayerInstance;
  
    
  public:
    PlayerManager(); 
     Player* GetPlayerInstance();
     
     void SetPlayerName();
    
    
    
};
