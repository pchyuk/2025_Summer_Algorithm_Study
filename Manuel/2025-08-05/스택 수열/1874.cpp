#include <iostream>
#include <vector>
#include <stack>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    stack<int> s;
    vector<char> result; // 연산 결과를 저장할 벡터 ('+' or '-')
    int current_num = 1; // 스택에 push될 다음 숫자 (1부터 시작)

    for(int i = 0; i < n; i++)
    {
        int target_num;
        cin >> target_num; // 주어진 수열의 현재 원소

        // Case 1: push될 다음 숫자가 target_num보다 작거나 같을 경우
        // target_num까지 push하기
        while(current_num <= target_num)
        {
            s.push(current_num);
            result.push_back('+');
            current_num++;
        }

        // Case 2: 스택의 top이 target_num과 같을 경우
        // pop 수행
        if(!s.empty() && s.top() == target_num)
        {
            s.pop();
            result.push_back('-');
        }

        // Case 3: 스택의 top이 target_num과 다른 경우 (수열 생성이 불가능한 경우)
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    // 모든 연산이 성공적으로 끝나면 결과 출력
    for(char op : result)
    {
        cout << op << endl;
    }

    return 0;
}