#pragma once
#include <windows.h>
#include <vector>
#include <string>

class EditConsole
{
public:
    EditConsole();
    ~EditConsole() = default;

    // 실시간으로 모든 창의 위치와 크기를 추적하여 출력합니다.
    void StartTracking();

private:
    // 추적할 자식 창들의 태그 이름 목록
    std::vector<std::string> m_tags;
    
    // 메인 콘솔 핸들
    HWND m_mainHwnd;
};