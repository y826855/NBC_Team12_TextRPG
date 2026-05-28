#pragma once
#include "Item/Shop.h"
#include <memory>

class BattleSystem;

enum class LobbyState
{
    None = 0,
    Battle,
    Shop,
};

class Lobby
{

    std::unique_ptr<BattleSystem> m_BattleSystem;
    std::unique_ptr<Shop> m_Shop;
    LobbyState m_LobbyState = LobbyState::None; 
    

public:
    Lobby();
    ~Lobby();
    
    void Intro();
    void ContentLoop();

private:
    void ShowMenu();
    void ChoiceMenu();
};
