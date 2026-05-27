#pragma once
#include <windows.h>
#include <string>
#include "ConsoleTypes.h"

using namespace std;

class MultiConsoleManager
{
public:
    MultiConsoleManager();
    ~MultiConsoleManager();

    // 메인 진입점에서 호출하여 모드를 판별하고 실행합니다.
    bool Initialize(int argc, char* argv[]);

    // 실제 자식 프로세스를 생성하는 함수
    void RunParentMode(const string& tag, const ConsoleWindowConfig& config);

    // 파이프에 메시지 전송 (부모 전용 인터페이스)
    bool SendToChild(const string& message);

    // 현재 연결 상태 확인
    bool IsConnected()
    {
        return hPipe != INVALID_HANDLE_VALUE;
    }

private:
    // 자식 모드: 부모 파이프에 연결 및 출력 루프
    void RunChildMode(const string& tag, int x, int y, int w, int h);
    // 자식 프로세스 종료 및 리소스 해제
    void Cleanup();

    HANDLE hPipe;
    HANDLE hChildProcess;
    const int bufferSize = 512;
    void InitChildConsole(); // 자식 콘솔의 설정을 초기화하는 함수 추가
};