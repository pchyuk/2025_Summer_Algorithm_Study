#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m; // 지도의 세로 크기 n, 가로 크기 m

    vector<vector<int>> grid(n, vector<int>(m)); // 원본 지도
    vector<vector<int>> distances(n, vector<int>(m, -1)); // 각 지점까지의 거리를 저장할 배열. -1로 초기화

    queue<pair<int, int>> q; // BFS를 위한 큐 (row, col)

    int target_r, target_c; // 목표 지점(2로 표기된 지점)의 좌표

    // 지도 입력 및 목표 지점 찾기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 2)
            {
                target_r = i;
                target_c = j;
            }
        }
    }

    // 목표 지점에서 BFS 시작
    q.push({target_r, target_c});
    distances[target_r][target_c] = 0; // 목표 지점의 거리를 0으로 초기화

    // 상하좌우 이동을 위한 방향 벡터
    int dr[] = {-1, 1, 0, 0}; // 위, 아래
    int dc[] = {0, 0, -1, 1}; // 왼쪽, 오른쪽

    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;
        int dist = distances[r][c];

        // 네 방향 모두 탐색
        for(int i = 0; i < 4; i++)
        {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            // 지도의 경계 내에 있는지 확인
            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m)
            {
                // 장애물(0)이 아니고, 아직 방문하지 않았다면(-1로 초기화된 곳)
                if(grid[new_r][new_c] == 1 && distances[new_r][new_c] == -1)
                {
                    distances[new_r][new_c] = dist + 1; // 거리 갱신
                    q.push({new_r, new_c}); // 큐에 추가
                }
            }
        }
    }

    // 결과 출력
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 원래 장애물이었던(0) 위치는 거리를 0으로 출력
            if(grid[i][j] == 0)
            {
                cout << 0 << " ";
            }
            // 그 외의 경우
            else
            {
                cout << distances[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}