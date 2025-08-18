#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
size_t M;
vector<int> nums;
vector<int> current;
vector<bool> used;

// 백트래킹 함수
void solve()
{
    // 기저 조건: 길이가 M인 순열이 완성되면 출력하고 함수 종료
    if(current.size() == M)
    {
        for(size_t i = 0; i < M; i++)
        {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    // 이전 단계에서 사용한 숫자
    int prev_num = 0;
    
    for(int i = 0; i < N; i++)
    {
        // 이미 사용한 숫자이거나, 이전 단계에서 사용한 숫자와 같을 경우 건너뜀
        if(!used[i] && nums[i] != prev_num)
        {
            current.push_back(nums[i]);
            used[i] = true;
            prev_num = nums[i];
            solve();
            // 백트래킹
            current.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    nums.resize(N);
    used.resize(N, false);

    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    solve();

    return 0;
}