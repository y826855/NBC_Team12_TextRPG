#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class InputHelper {
public:
    // 숫자 입력을 범위를 지정해서 받는 함수
    template <typename T>
    static T GetValidInput(string message, T min, T max) {
        T input;
        while (true) {
            cout << message;
            cin >> input;

            // 1. 숫자가 아닌 값이 들어왔는지 확인 (failbit)
            // 2. 지정한 범위를 벗어났는지 확인
            if (cin.fail() || input < min || input > max) {
                cout << "[오류] " << min << " ~ " << max << " 사이의 값을 입력해주세요." << endl;
                cin.clear(); // 에러 비트 초기화
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 남은 엔터 제거
                return input;
            }
        }
    }

    // 여러 개의 입력을 한 번에 받아 같은 범위로 검증하는 함수
    template <typename T>
    static vector<T> GetMultiValidInput(string message, int count, T min, T max) {
        while (true) {
            cout << message;
            vector<T> inputs(count);
            bool allValid = true;

            for (int i = 0; i < count; ++i) {
                if (!(cin >> inputs[i])) {
                    allValid = false;
                    break;
                }
                
                if (inputs[i] < min || inputs[i] > max) {
                    allValid = false;
                    break;
                }
            }

            if (!allValid || cin.fail()) {
                cout << "[오류] 모든 값은 " << min << " ~ " << max << " 사이의 숫자여야 합니다." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return inputs;
            }
        }
    }
    
    // 이름 입력 (길이 제한 등)
    static string GetValidName(string message, int minLen, int maxLen = 10) {
        string input;
        while (true) {
            cout << message;
            cin >> input;

            if (input.length() < minLen || input.length() > maxLen) {
                cout << "[오류] 이름은 " << minLen << "~" << maxLen << "자 사이여야 합니다." << endl;
            } else {
                return input;
            }
        }
    }
};