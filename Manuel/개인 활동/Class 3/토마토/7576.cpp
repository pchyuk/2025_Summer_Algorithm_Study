/*
초기에 익은 토마토에서 동시에 BFS를 시작하여 모든 토마토를 익히는 과정을 다루는 문제

1. 초기 상태:
처음부터 익어 있는 모든 토마토를 BFS 큐에 넣고, 이들의 위치를 기준으로 탐색 시작
2. BFS 탐색:
    2-1: 큐에는 {행, 열, 시간}을 넣음. 모든 익은 토마토의 위치와 시간을 큐에 넣음.
    2-2: 큐에서 한 칸씩 꺼내어 상하좌우 인접한 칸들을 확인.
    2-3: 인접한 칸이 유효 범위에 있고, 아직 익지 않았다면, 해당 칸을 익었다고 표기하고 큐에 {인접한 행, 인접한 열, 현재 시간 + 1}을 넣음.
3. BFS가 종료되면 큐에 들어 있는 마지막 시간 값이 모든 토마토가 익는 최소 시간이 됨.
4. 예외
    4-1: 만약 BFS가 끝나도 익지 않은 토마토가 남아있다면 -1 출력
    4-2: 처음부터 모두 익어 있다면 0 출력
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define endl "\n"

using namespace std;

// 상하좌우 이동 방향 벡터
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N; // 가로 M, 세로 N
    vector<vector<int>> box(N, vector<int>(M));
    queue<tuple<int, int, int>> q; // {x, y, time}
    int unripe_tomatoes = 0; // 익지 않은 토마토의 개수

    // 상자 상태 입력 및 초기에 익은 토마토 위치 찾기
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if(box[i][j] == 1)
            {
                q.push({i, j, 0});
            }
            else if(box[i][j] == 0)
            {
                unripe_tomatoes++;
            }
        }
    }
    
    if(unripe_tomatoes == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int max_time = 0;

    // BFS 시작
    while(!q.empty())
    {
        int x, y, time;
        tie(x, y, time) = q.front();
        q.pop();

        max_time = time;

        // 상하좌우 탐색
        for(int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            // 경계 내에 있고, 익지 않은 토마토라면:
            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && box[new_x][new_y] == 0)
            {
                box[new_x][new_y] = 1; // 토마토가 익었다고 표기
                unripe_tomatoes--; // 익지 않은 토마토 개수 감소
                q.push({new_x, new_y, time + 1});
            }
        }
    }

    // 모든 토마토가 익었는지 확인
    if(unripe_tomatoes == 0)
    {
        cout << max_time << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}