#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string expression; // 식을 입력받을 문자열
    cin >> expression;
    int result = 0; // 최종 결과
    string current_num_str = ""; // 현재 숫자를 저장할 문자열
    bool after_first_minus = false; // 첫 "-" 연산자 이후인지 여부를 나타내는 플래그

    for(char ch: expression) // 식의 각 문자 순회
    {
        if(ch == '+' || ch == '-') // 연산자를 만나면, 그 전까지 파싱한 숫자 처리
        {
            int num_val = stoi(current_num_str); // 문자열을 정수로 변환
            if(after_first_minus) // 첫 번째 '-'를 만나면 모든 숫자를 뺌
            {
                result -= num_val;
            }
            else // 첫 '-'를 만나기 전이면 숫자를 더함
            {
                result += num_val;
            }
            if (ch == '-')
            {
                after_first_minus = true; // 현재 연산자가 '-'라면 after... 플래그를 true로 설정
            }
            current_num_str = ""; // 현재 숫자 문자열 초기화
        }
        else
        {
            current_num_str += ch; // 숫자를 만나면 현재 숫자 문자열에 추가
        }
    }

    // 마지막으로 파싱된 숫자 처리 (식의 마지막은 항상 숫자이기 때문)
    int last_num_val = stoi(current_num_str);
    if(after_first_minus)
    {
        result -= last_num_val;
    }
    else
    {
        result += last_num_val;
    }
    cout << result << "\n";
    return 0;
}