#pragma once
#include "../Utility/Singleton.h"
#include "MultiConsoleManager.h"
#include "ConsoleTypes.h"
#include "ConsoleLogStream.h"
#include <string>
#include <map>

using namespace std;

class ConsoleController : public Singleton<ConsoleController>
{
    friend class Singleton<ConsoleController>;
public:
    ConsoleController() = default;
    ~ConsoleController() override;

    // 시스템 초기화 (자식 모드 판별 및 엔진 설정)
    bool Initialize(int argc, char* argv[]);

    // 특정 태그의 콘솔창을 열거나 유지
    void AddConsole(EConsoleTag tag);
    
    // 콘솔창에 메시지 전송 (닫혀있으면 자동으로 열고 전송)
    void Message(EConsoleTag tag, const string& message);
    void Message(const string& message);

    void ClearAndMessage(EConsoleTag tag, const string& message);
    
    // 특정 태그를 지정해 콘솔창 닫기 (현재는 단일창 종료)
    void CloseConsole(EConsoleTag tag);

    // 특정 태그의 콘솔창 화면 지우기
    void Clear(EConsoleTag tag);

    // 모든 자식 콘솔창 종료
    void CloseAll();


private:
    string TagToString(EConsoleTag tag);
    map<EConsoleTag, MultiConsoleManager*> m_managers;
};
