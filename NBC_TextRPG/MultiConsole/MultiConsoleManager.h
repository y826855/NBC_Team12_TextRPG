#pragma once
#include <windows.h>
#include <string>

class MultiConsoleManager {
public:
    MultiConsoleManager();
    ~MultiConsoleManager();

    // 메인 진입점에서 호출하여 모드를 판별하고 실행합니다.
    // 부모 모드일 경우 true를 반환하여 게임 로직을 진행하게 합니다.
    bool Initialize(int argc, char* argv[]);

    // 파이프에 메시지 전송 (부모 전용 인터페이스)
    bool SendToChild(const std::string& message);

private:
    // 부모 모드: 파이프 생성 및 자식 프로세스 실행
    void RunParentMode();
    // 자식 모드: 부모 파이프에 연결 및 출력 루프
    void RunChildMode();
    // 자식 프로세스 종료 및 리소스 해제
    void Cleanup();

private:
    HANDLE hPipe;
    HANDLE hChildProcess;
    const std::string pipeName = "\\\\.\\pipe\\NBC_RPG_ConsolePipe";
    const int bufferSize = 512;
};