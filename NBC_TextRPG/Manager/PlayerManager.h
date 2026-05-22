#pragma once
#include "../Utility/Singleton.h"
#define GetPlayer() PlayerManager::GetInstance()->GetPlayerInstance()

class Player;


class PlayerManager : public Singleton<PlayerManager>
{
  
private:
  Player* PlayerInstance;
  
    
  public:
    PlayerManager(); 
     Player* GetPlayerInstance();
  
    
    
};
