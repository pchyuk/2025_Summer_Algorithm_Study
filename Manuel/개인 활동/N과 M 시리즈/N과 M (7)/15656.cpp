/*
1. 입력받은 N개의 수를 오름차순으로 정렬
2. 숫자 중복이 가능하므로 used 배열은 쓸 필요 없음
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

    for(int i = 0; i < N; i++)
    {
        current_selection.push_back(nums[i]);
        solve();
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
    
    solve();

    return 0;
}