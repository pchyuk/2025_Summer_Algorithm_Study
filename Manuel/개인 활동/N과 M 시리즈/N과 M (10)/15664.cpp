/*
입력 배열에 중복된 숫자가 있어도 결과 수열이 중복되지 않도록 해야 함.
백트래킹을 통해 조합을 생성하되, 현재 재귀 단계에서 같은 숫자를 여러 번 시도하지 않게 해야 함.
    - for 루프에서 이전에 사용한 숫자와 같은 숫자를 건너뛰는 기능 추가
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
        for(size_t i = 0; i < M; i++)
        {
            cout << current_selection[i] << ' ';
        }
        cout << endl;
        return;
    }

    // 현재 재귀 단계에서 이전에 사용한 숫자
    int prev_num = 0;

    // start_index부터 N - 1까지의 모든 숫자를 탐색
    for(size_t i = start_index; i < nums.size(); i++)
    {
        // 이전 단계에서 사용한 숫자와 같을 경우 건너뜀
        if(nums[i] != prev_num)
        {
            current_selection.push_back(nums[i]);
            // 다음 시작점은 현재 인덱스의 다음으로 설정하여 비내림차순으로 만듦
            solve(i + 1);
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