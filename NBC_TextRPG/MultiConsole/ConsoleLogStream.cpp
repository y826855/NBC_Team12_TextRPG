#include "ConsoleLogStream.h"
#include "ConsoleController.h"

ConsoleLogStream::ConsoleLogStream(EConsoleTag tag) 
    : m_tag(tag) 
{
}

ConsoleLogStream::~ConsoleLogStream()
{
    // 소멸 시점에 싱글톤을 통해 메시지 전송
    ConsoleController::GetInstance()->Message(m_tag, m_oss.str());
}