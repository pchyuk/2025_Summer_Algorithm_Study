#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"

const int MAX_POS = 100001; // 최대 위치 + 1

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K; // 수빈의 위치 N, 동생의 위치 K

    // 각 위치에 도달하는 데 걸린 시간이 저장될 배열
    // -1은 아직 방문하지 않았다는 뜻
    vector<int> visited_time(MAX_POS, -1);
    // BFS를 위한 큐 {위치, 시간} 쌍을 저장
    queue<pair<int, int>> q;

    // 수빈의 시작 위치와 시간 0을 큐에 넣고 방문 처리
    q.push({N, 0});
    visited_time[N] = 0;

    // BFS 시작
    while(!q.empty())
    {
        int current_pos = q.front().first;
        int time = q.front().second;
        q.pop();

        // 동생의 위치에 도달하면 최단 시간 반환
        if(current_pos == K)
        {
            cout << time << endl;
            return 0;
        }

        // 다음 이동 가능한 위치를 탐색
        // 1. X - 1
        int next_pos_minus = current_pos - 1;
        if(next_pos_minus >= 0 && visited_time[next_pos_minus] == -1)
        {
            visited_time[next_pos_minus] = time + 1;
            q.push({next_pos_minus, time + 1});
        }

        // 2. X + 1
        int next_pos_plus = current_pos + 1;
        if(next_pos_plus < MAX_POS && visited_time[next_pos_plus] == -1)
        {
            visited_time[next_pos_plus] = time + 1;
            q.push({next_pos_plus, time + 1});
        }

        // 3. X * 2
        int next_pos_multi = current_pos * 2;
        if(next_pos_multi < MAX_POS && visited_time[next_pos_multi] == -1)
        {
            visited_time[next_pos_multi] = time + 1;
            q.push({next_pos_multi, time + 1});
        }
    }

    return 0;
}