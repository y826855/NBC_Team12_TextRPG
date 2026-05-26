#pragma once
#include <string>

#include "../Utility/Singleton.h"
#define GetPlayer() PlayerManager::GetInstance()->GetPlayerInstance()
#define SetName() PlayerManager::SetPlayerName();

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
