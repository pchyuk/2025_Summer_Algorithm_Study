/*
1. 같은 수를 여러 번 골라도 됨
2. 고른 수열은 비내림차순이어야 함

먼저 입력받은 N개의 수를 정렬한 다음, for 루프의 시작점을 현재 선택한 숫자의 인덱스로 설정한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M;
vector<int> nums;
vector<int> current_selection;

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

    for(size_t i = start_index; i < nums.size(); i++)
    {
        current_selection.push_back(nums[i]);
        solve(i);
        current_selection.pop_back();
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