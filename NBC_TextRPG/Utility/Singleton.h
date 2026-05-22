#pragma once

template <typename T>
class Singleton
{
protected:
    // 자식 클래스에서 생성자를 구현할 수 있도록 protected로 설정
    Singleton() = default;
    virtual ~Singleton() = default;

    // 복사와 대입을 원천 차단
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // 유일한 인스턴스를 반환하는 static 함수
    static T* GetInstance()
    {
        // static 지역 변수는 프로그램 실행 중 단 한 번만 초기화됩니다. (Thread-safe)
        static T instance;
        return &instance;
    }
};