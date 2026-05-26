#include <iostream>

#include "MultiConsole/ConsoleController.h"
#include "Lobby.h"
#include "MultiConsole/EditConsole.h"

using namespace std;

void PrepareWindow()
{
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::Main);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::UpperRight);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::LowerRight);

    std::cout << endl << endl;
}

void EditWindow()
{
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::Main);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::UpperRight);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::LowerRight);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::LargePopup);
    ConsoleController::GetInstance()->AddConsole(EConsoleTag::SmallPopup);
    
    // 위치 측정 도구 실행
    EditConsole editor;
    editor.StartTracking();
}

int main(int argc, char* argv[])
{
    if (!ConsoleController::GetInstance()->Initialize(argc, argv))
    {
        return 0;
    }

    //창 수정을 위한 함수. 필요시 주석 해제
    //EditWindow();
    
    PrepareWindow();

    Lobby lobby;
    lobby.Intro();
    lobby.ContentLoop();


    ConsoleController::GetInstance()->CloseAll();

    return 0;
}
