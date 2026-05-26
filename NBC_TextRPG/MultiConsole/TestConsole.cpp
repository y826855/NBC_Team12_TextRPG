#include "TestConsole.h"

#include <iostream>

#include "MultiConsoleManager.h"

int TestConsole::TestOpenConsole(int argc, char* argv[])
{
    MultiConsoleManager consoleManager;
    if (!consoleManager.Initialize(argc, argv)) {
        return 0; // 자식 모드라면 여기서 종료 (MultiConsoleManager::RunChildMode에서 exit(0) 호출)
    }

    // --- 여기서부터 부모(게임) 로직 ---
    std::cout << "RPG 게임을 시작합니다..." << std::endl;
    consoleManager.SendToChild("게임 시작!");

    // 예시: 게임 루프에서 메시지를 자식 콘솔로 보냄
    std::string gameInput;
    while (true) {
        std::cout << "게임 입력 (exit 입력 시 종료): ";
        std::getline(std::cin, gameInput);
        if (gameInput == "exit") {
            consoleManager.SendToChild("exit"); // 자식에게 종료 신호
            break;
        } 
        consoleManager.SendToChild("게임 메시지: " + gameInput);
    }
    return 0;
}
