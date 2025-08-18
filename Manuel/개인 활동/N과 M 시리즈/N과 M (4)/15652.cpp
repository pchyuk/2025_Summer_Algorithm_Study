/*
문제는 이전과 동일, 그러나:
1. 같은 수를 여러 번 골라도 됨
2. 고른 수열은 비내림차순(이전 숫자보다 크거나 같아야 함)
*/

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<int> current_selection;

/*
start_num: 이번 재귀에서 숫자를 고르기 시작할 시작점
재귀를 start_num부터 시작하면 for 루프가 현재 선택한 숫자보다 크거나 같은 숫자부터 시작함.
*/
void solve(int start_num)
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
    
    // start_num부터 N까지의 모든 숫자를 탐색
    for(int i = start_num; i <= N; i++)
    {
        current_selection.push_back(i);
        solve(i);
        current_selection.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    solve(1); // 1부터 시작

    return 0;
}