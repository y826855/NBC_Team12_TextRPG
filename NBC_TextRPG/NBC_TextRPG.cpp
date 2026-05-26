#include <iostream>

#include "MultiConsole/ConsoleController.h"
#include "Lobby.h"

using namespace std;

void PrepareWindow()
{
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::Main);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::UpperRight);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::LowerRight);

    std::cout << endl << endl;
}

int main(int argc, char* argv[])
{
    if (!ConsoleController::GetInstance()->Initialize(argc, argv))
    {
        return 0;
    }

    /*
    //창 위치를 지정할때 주석 해제
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::Main);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::UpperRight);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::LowerRight);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::LargePopup);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::SmallPopup);
    
    // 위치 측정 도구 실행
    EditConsole editor;
    editor.StartTracking();
    */

    PrepareWindow();
    
    Lobby lobby;
    lobby.Intro();
    lobby.ContentLoop();

    ConsoleController::GetInstance()->CloseAll();

    return 0;
}
