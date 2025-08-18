/*
조건:
1. 같은 수를 여러 번 고를 수 있음
2. 고른 수열은 비내림차순
3. 결과 수열은 중복되면 안 됨

해결 방안:
1. 입력받은 수를 정렬 (비내림차순 보장)
2. for 루프 안에서 직전에 사용한 숫자와 현재 숫자가 같으면 건너뛰기
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M;
vector<int> nums;
vector<int> current_selection;

// start_index: 이번 재귀에서 숫자를 고르기 시작할 인덱스
void solve(int start_index)
{
    if(current_selection.size() == M)
    {
        for(size_t i  = 0; i < M; i++)
        {
            cout << current_selection[i] << ' ';
        }
        cout << endl;
        return;
    }

    int prev_num = 0;

    // start_index부터 N - 1까지의 모든 숫자를 탐색
    for(size_t i = start_index; i < nums.size(); i++)
    {
        if(nums[i] != prev_num)
        {
            current_selection.push_back(nums[i]);
            solve(i);
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
    solve(0);

    return 0;
}