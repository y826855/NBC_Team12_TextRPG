#pragma once
#include <sstream>
#include "ConsoleTypes.h"

class ConsoleController;

#define C_LOG(tag) ConsoleLogStream(tag)

class ConsoleLogStream
{
public:
    ConsoleLogStream(EConsoleTag tag);
    ~ConsoleLogStream();

    template <typename T>
    ConsoleLogStream& operator<<(const T& value)
    {
        m_oss << value;
        return *this;
    }

    // std::endl 지원
    ConsoleLogStream& operator<<(std::ostream& (*manip)(std::ostream&))
    {
        manip(m_oss);
        return *this;
    }

private:
    std::ostringstream m_oss;
    EConsoleTag m_tag;
};