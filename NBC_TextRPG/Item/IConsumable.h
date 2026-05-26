#pragma once

#include <string>

using namespace std;

// 소비 가능한 아이템이 구현해야 할 인터페이스
class IConsumable
{
public:
    virtual ~IConsumable() = default; // 가상 소멸자
    virtual void Use() = 0;           // 순수 가상 함수: 아이템 사용
};