#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m)); // graph, visit
    queue<pair<int, int>> q;

    // 초기 상태 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) // 익은 건 큐에 삽입
                q.emplace(i, j);
        }
    }

    // 각 익인 토마토에 대해서 상, 하, 좌, 우를 탐색할 것이다.
    // 행렬이므로 dx = +1이면 행이 증가(세로로 이동), dy = +1이면 열이 증가(가로로 이동)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // bfs 실행
    while (!q.empty()) { // bfs는 큐가 빌때까지 진행
        auto [x, y] = q.front();
        q.pop(); // 큐에서 하나의 원소를 꺼내와서 bfs실행

        // 상, 하, 좌, 우에 대해서 안 익은 토마토는 익히고
        // 빈칸, 익은 토마토는 스킵
        for (int i = 0; i < 4; i++) {
            // 탐색 좌표 설정
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 상자를 벗어나면 스킵
            if (box[nx][ny] != 0) continue; // 이미 익거나 빈칸이면 스킵

            // 날짜를 업그레이드 한다. 행렬의 숫자는 0일차를 나타낸다.
            // 문제의 조건에 맞추기 위해서 마지막에 1을 빼야 한다.
            box[nx][ny] = box[x][y] + 1;
            q.emplace(nx, ny); // 새롭게 토마토가 익었으니 큐에 추가한다.
        }
    }

    int max_day = 0; // 최대 걸린 일 수 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 0) { // 아직도 안 익은게 있으면 불가능한 것이므로 -1 출력
                cout << "-1" << '\n';
                return 0;
            }
            max_day = max(max_day, box[i][j]); // 계속 큰 값을 갱신해가면서 최대값을 찾는다.
        }
    }

    cout << max_day - 1 << '\n';
    return 0;
}