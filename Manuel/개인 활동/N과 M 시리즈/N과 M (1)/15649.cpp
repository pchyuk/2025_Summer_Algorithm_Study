/*
같은 수를 여러 번 고르거나, 순서가 다른 구성의 수열은 다른 것으로 간주
백트래킹 알고리즘 사용:
    해결책을 찾는 과정에서 더이상 해를 찾을 수 없는 경로라고 판단되면 되돌아가 다르 경로를 탐색
*/

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<int> current_selection;
vector<bool> used;

// 백트래킹 함수
void solve()
{
    // 기저 조건: 길이가 M인 순열이 완성되면 출력하고 함수 종료
    if(current_selection.size() == M)
    {
        for(size_t i = 0; i < M; i++)
        {
            cout << current_selection[i] << ' ';
        }
        cout << endl;
        return;
    }

    // 1부터 N까지 모든 숫자를 탐색
    for(int i = 1; i <= N; i++)
    {
        // i번째 숫자가 아직 사용되지 않았으면:
        if(!used[i])
        {
            used[i] = true;
            // 순열에 현재 숫자 추가
            current_selection.push_back(i);
            // 다음 숫자를 선택하기 위한 재귀 호출
            solve();
            // 백트래킹: 현재 숫자의 상태를 되돌림
            current_selection.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    // 인덱스 1부터 N까지 사용하기 위해 N + 1 크기로 설정
    used.resize(N + 1, false);
    
    solve();
    
    return 0;
}