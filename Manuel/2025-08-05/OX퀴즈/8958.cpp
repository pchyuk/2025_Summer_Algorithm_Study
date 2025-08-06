#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // 테스트 케이스의 수 입력

    for(int i = 0; i < T; i++)
    {
        string result;
        cin >> result; // OX 퀴즈 결과 문자열 입력

        int total_score = 0;
        int streak = 0;

        // 문자열을 순회하며 점수 계산
        for(char c : result)
        {
            if(c == 'O' || c == 'o')
            {
                streak++;
                total_score += streak;
            }
            else
            {
                streak = 0;
            }
        }
        cout << total_score << endl;
    }
    return 0;
}