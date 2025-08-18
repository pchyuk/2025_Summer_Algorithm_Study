/*
조건: 같은 수를 여러 번 고를 수 있음, 결과 수열은 중복되면 안 됨
주의할 점: 입력 배열에 중복된 숫자가 있을 수 있고, 같은 숫자를 여러 번 사용할 수 있음
해결 방법: for 루프 안에서 직전에 사용한 숫자와 현재 숫자가 같으면 건너뛰게 함
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M;
vector<int> nums;
vector<int> current_selection;

void solve()
{
    if(current_selection.size() == M)
    {
        for(size_t i = 0; i < M; i++)
        {
            cout << current_selection[i] << ' ';
        }
        cout << endl;
        return;
    }

    // 현재 재귀 단계에서 이전에 사용한 숫자
    int prev_num = 0;

    // nums 배열의 모든 숫자를 탐색
    for(size_t i = 0; i < nums.size(); i++)
    {
        // 직전에 사용한 숫자가 같으면 건너뜀
        if(nums[i] != prev_num)
        {
            current_selection.push_back(nums[i]);
            solve();
            current_selection.pop_back();
            prev_num = nums[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    nums.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    solve();

    return 0;
}