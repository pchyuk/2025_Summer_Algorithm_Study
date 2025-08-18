/*
백트래킹 문제.
1번 문제와 달리 숫자를 여러 번 쓸 수 있음.
따라서 used 배열을 사용할 필요 없음.
*/

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<int> current_selection;

// 백트래킹 함수 (설명은 1번 문제 참고)
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

    for(int i = 1; i <= N; i++)
    {
        current_selection.push_back(i);
        solve();
        current_selection.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    solve();

    return 0;
}