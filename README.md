# NBC_Team12_TextRPG
내일배움 캠프에서 진행하는 TEXT RPG 제작

## 🗺️ 노션
https://www.notion.so/teamsparta/12-3672dc3ef5148068a6c5c01bba994dcb?v=3672dc3ef514805ea946000c5316fdd5&source=copy_link

## 📝 기획 및 설계구조
https://miro.com/app/board/uXjVLi9zwcE=/

classDiagram
    %% 1. 클래스 및 인터페이스/추상 클래스 정의
    class main {
    }

    class Lobby {
        -m_BattleSystem
        -m_Shop
        +Lobby()
    }

    class Inventory {
        <<static>>
        -unordered_map~EItem, int~ ItemContainer
        +AddItem(EItem itemID)
        +UseItem(EItem itemID)
    }

    class ItemManager {
        <<static>>
        -unordered_map~EItem, int~ ItemContainer
        +AddItem(EItem itemID)
        +UseItem(EItem itemID)
    }

    class ItemBase {
        +GetPrice()
        +ItemBase(string name, int price)
    }

    class Shop {
        -BuyItem()
        -SellItem()
        +OpenShop()
    }

    class BattleSystem {
        -MonsterSpawn()
        -NormalBattleLoop()
        +BattleStart()
    }

    class PlayerManager {
        <<static>>
        -Player PlayerInstance
        +SetPlayerName()
        +GetPlayer()
    }

    class Player {
        -LevelUp()
        +Attack(Monster* monster)
        +takeDamage(int Damage)
    }

    class Monster {
        <<Abstract>>
        -SetStat()
        +virtual void Attack()*
        +TakeDamage()
    }

    class Ghoul {
        -SetStat()
        +Attack() override
    }

    class Lich {
        -SetStat()
        +Attack() override
    }

    %% 2. 관계 정의 (UML 기호와 방향 완벽 매핑)
    main --> Lobby
    
    Lobby *--> Shop
    Lobby *--> BattleSystem
    
    Shop ..> Inventory : Use
    Shop ..> PlayerManager : Use
    BattleSystem ..> Inventory : Use
    BattleSystem ..> PlayerManager : Use
    BattleSystem ..> Monster : Use
    
    ItemManager ..> Inventory : Use
    ItemManager *--> ItemBase
    
    PlayerManager *--> Player
    
    Monster <|-- Ghoul
    Monster <|-- Lich
