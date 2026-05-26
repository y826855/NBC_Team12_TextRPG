#pragma once

#define CONSOLE_TITLE_PREFIX "Child Console - "
#define TITLE_MAIN        "Main"
#define TITLE_UPPER_RIGHT "UpperRight"
#define TITLE_LOWER_RIGHT "LowerRight"
#define TITLE_LARGE_POPUP "LargePopup"
#define TITLE_SMALL_POPUP "SmallPopup"

enum class EConsoleTag
{
    Main,
    UpperRight,
    LowerRight,
    LargePopup,
    SmallPopup,
};

// 각 콘솔 창의 초기 설정 정보를 담는 구조체
struct ConsoleWindowConfig
{
    int x;
    int y;
    int width;
    int height;
    int cols; // 텍스트 열 수
    int rows; // 텍스트 행 수
};