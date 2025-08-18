/*
1. 수열은 오름차순
2. 수열에는 같은 수를 고를 수 없음
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
    }

    for(size_t i = start_index; i < nums.size(); i++)
    {
        current_selection.push_back(nums[i]);
        // 다음 시작점은 현재 숫자(i)의 다음 인덱스로 설정하여 오름차순 보장
        solve(i + 1);
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
    solve(0); // 0번 인덱스부터 시작

    return 0;
}