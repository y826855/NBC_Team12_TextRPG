#pragma once
#include "Item/Shop.h"

class BattleSystem;

enum class LobbyState
{
    None = 0,
    Battle,
    Shop,
};

class Lobby
{

    BattleSystem* m_BattleSystem = nullptr;
    Shop* m_Shop = nullptr;
    LobbyState m_LobbyState = LobbyState::None; 
    
public:
    Lobby();
    void Intro();
    void ContentLoop();

private:
    void ShowMenu();
    void ChoiceMenu();
};
