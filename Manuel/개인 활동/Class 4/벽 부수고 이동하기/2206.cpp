/*
BFS 사용 - 최단 경로 문제이므로
단순한 2차원 visited 배열로는 해결 불가능
    - 벽을 부수고 온 경로 vs 벽을 안 부수고 온 경로
    - 같은 위치에 도달해도 벽을 부술 수 있는 상태가 다름
    따라서 3차원 배열을 이용해야 함
상태 관리: 큐에 {x, y, distance, wall_broken} 저장
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

struct Point
{
    int x, y, dist, wall_broken;
    Point(int x, int y, int dist, int wall_broken):
        x(x), y(y), dist(dist), wall_broken(wall_broken) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> graph(n);
    for(int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    // BFS
    queue<Point> q;
    q.push(Point(0, 0, 1, 0));

    // 3차원 방문 처리: visited[x][y][wall_broken]
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    visited[0][0][0] = true;

    // 상하좌우 방향 벡터
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty())
    {
        Point current = q.front();
        q.pop();

        // 도착 지점에 도달한 경우
        if(current.x == n - 1 && current.y == m - 1)
        {
            cout << current.dist << endl;
            return 0;
        }

        // 4방향 탐색
        for(int i = 0; i < 4; i++)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // 범위를 벗어나면 건너뛰기
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            // 이동할 곳이 빈 공간인 경우 ('0')
            if(graph[nx][ny] == '0')
            {
                if(!visited[nx][ny][current.wall_broken])
                {
                    visited[nx][ny][current.wall_broken] = true;
                    q.push(Point(nx, ny, current.dist + 1, current.wall_broken));
                }
            }
            else // 이동할 곳이 벽인 경우 ('1')
            {
                // 아직 벽을 부수지 않았을 때만 벽을 부술 수 있음
                if(current.wall_broken == 0 && !visited[nx][ny][1])
                {
                    visited[nx][ny][1] = true;
                    q.push(Point(nx, ny, current.dist + 1, 1));
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}