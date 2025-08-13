#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<int> current_list;

// 백트래킹 함수
void dfs(int start_num)
{
    // 기저 조건: M개의 숫자를 모두 골랐다면
    if(current_list.size() == M)
    {
        // 현재 리스트 출력
        for(int i = 0; i < M; i++)
        {
            cout << current_list[i] << " ";
        }
        cout << endl;
        return;
    }
    // start_num부터 N까지 모든 숫자를 탐색
    for(int i = start_num; i <= N; i++)
    {
        current_list.push_back(i); // 현재 숫자를 리스트에 추가
        dfs(i + 1); // 다음 탐색은 i + 1부터 시작 (오름차순 유지)
        current_list.pop_back(); // 백트래킹: 추가한 숫자 제거
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    dfs(1);

    return 0;
}