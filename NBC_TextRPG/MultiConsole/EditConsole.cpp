#include "EditConsole.h"
#include "ConsoleTypes.h"
#include <iostream>

using namespace std;

EditConsole::EditConsole()
{
    m_mainHwnd = GetConsoleWindow();
    m_tags = { TITLE_UPPER_RIGHT, TITLE_LOWER_RIGHT, TITLE_LARGE_POPUP, TITLE_SMALL_POPUP };
}

void EditConsole::StartTracking()
{
    if (m_mainHwnd == nullptr)
    {
        return;
    }

    while (true)
    {
        system("cls");
        cout << "==================================================" << endl;
        cout << "      [실시간 멀티 콘솔 위치/사이즈 측정기]       " << endl;
        cout << "==================================================" << endl;

        // 1. 메인 창 정보 출력
        RECT mRect;
        if (GetWindowRect(m_mainHwnd, &mRect))
        {
            int x = mRect.left;
            int y = mRect.top;
            int w = mRect.right - mRect.left;
            int h = mRect.bottom - mRect.top;

            cout << "[Main Console] Pos: " << x << ", " << y 
                 << " | Size: " << w << "x" << h << endl;
        }

        // 2. 자식 창들 정보 출력 (타이틀로 검색)
        for (const string& tag : m_tags)
        {
            string title = string(CONSOLE_TITLE_PREFIX) + tag;
            HWND hChild = FindWindowA(nullptr, title.c_str());
            
            if (hChild != nullptr)
            {
                RECT cRect;
                if (GetWindowRect(hChild, &cRect))
                {
                    int cx = cRect.left;
                    int cy = cRect.top;
                    int cw = cRect.right - cRect.left;
                    int ch = cRect.bottom - cRect.top;

                    cout << "[" << tag << "] Pos: " << cx << ", " << cy 
                         << " | Size: " << cw << "x" << ch << endl;
                }
            }
            else
            {
                cout << "[" << tag << "] 창을 찾는 중..." << endl;
            }
        }

        cout << "==================================================" << endl;
        cout << "원하는 위치에 창들을 배치하고 수치를 기록하세요." << endl;
        cout << "종료하려면 Ctrl+C를 누르세요." << endl;

        // CPU 점유율 방지를 위한 대기
        Sleep(200);
    }
}