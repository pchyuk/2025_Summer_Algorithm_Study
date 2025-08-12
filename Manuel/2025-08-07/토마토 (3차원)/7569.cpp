#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define endl "\n"

using namespace std;

// 6방향 이동을 위한 방향 벡터
int dz[] = {0, 0, 0, 0, 1, -1};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 가로 M, 세로 N, 높이 H
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    queue<tuple<int, int, int, int>> q; // {z, x, y, time}

    int unripe_tomatoes = 0; // 익지 않은 토마토의 개수

    // 상자의 상태 입력 및 초기에 익은 토마토 위치 찾기
    for(int z = 0; z < H; z++)
    {
        for(int x = 0; x < N; x++)
        {
            for(int y = 0; y < M; y++)
            {
                cin >> box[z][x][y];
                if(box[z][x][y] == 1)
                {
                    q.push({z, x, y, 0});
                }
                else if(box[z][x][y] == 0)
                {
                    unripe_tomatoes++;
                }
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
        int z, x, y, time;
        tie(z, x, y, time) = q.front();
        q.pop();

        max_time = time;

        // 6방향 탐색
        for(int i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 경계 내에 있고, 익지 않은 토마토라면:
            if(nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M && box[nz][nx][ny] == 0)
            {
                box[nz][nx][ny] = 1; // 토마토를 익히고
                unripe_tomatoes--; // 익지 않은 토마토 개수를 감소시킴
                q.push({nz, nx, ny, time + 1});
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