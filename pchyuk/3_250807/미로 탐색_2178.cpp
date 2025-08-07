/* 나의 풀이 : 박찬혁 */
/* 풀이 과정 : (0,0)에서 시작하여 상하좌우를 찾고, 방문하지 않았고 유효한 값이면
해당 위치의 좌표값을 1 올려준다. */
/* 사용된 알고리즘 : 그래프 이론(BFS) */
/* 링크 : https://www.acmicpc.net/problem/7576 */

#include <iostream>
#include <queue>
using namespace std;

int maze[101][101]; // 미로판
bool visited[101][101]; // 미로판을 방문했는지의 여부

int dr[] = {-1, 1, 0, 0}; // 상하
int dc[] = {0, 0, -1, 1}; // 좌우

void BFS(int x, int y, int n, int m){
    queue<pair<int, int>> q; // 좌표쌍을 저장하기 위한 큐
    q.push(make_pair(x,y)); // 좌표쌍을 큐에 푸시한다.
    while(!q.empty()){ // 큐가 비어있지 않다면
        int tmp_x = q.front().first; // 좌표쌍의 첫번째 원소를 x에
        int tmp_y = q.front().second; // 두 번째 원소를 y에 넣고
        q.pop(); // 팝 해준다.

        for(int i=0; i<4; i++){
            int dx = tmp_x + dr[i]; // 기준 위치로부터 상하좌우를 검색하기 위한 좌표
            int dy = tmp_y + dc[i];

            if(dx >= 0 && dx < n && dy >= 0 && dy < m){ // 좌표가 범위 내에 있다면
                if(!visited[dx][dy] && maze[dx][dy] != 0){ // 해당 좌표에 방문하지 않았고 그 값이 0이 아니라면
                    visited[dx][dy] = true; // 방문 표시를 해주고
                    maze[dx][dy] = maze[tmp_x][tmp_y] + 1; // 위치의 값을 기준 좌표 값보다 1 크게 바꿔준다.(미로의 이동 횟수를 나타내게 됨)
                    q.push(make_pair(dx, dy)); // 현재 좌표쌍을 큐에 넣는다.
                }
            }
        }
        if(tmp_x == n-1 && tmp_y == m-1) return; // 좌표가 최종 위치까지 도달했다면 함수 종료
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string tmp; // 값들을 입력받기 위한 스트링 변수 선언 - 값들이 공백 없이 붙어있다 해서 사용한 방법
        cin >> tmp; // 스트링을 입력받고
        for(int j=0; j<m; j++){ // 스트링을 m개로 조각내어
            maze[i][j] = tmp[j] - '0'; // 정수로 바꾸어서 배열에 저장한다.
        }
    }

    BFS(0,0,n,m); // 함수 호출


    cout << maze[n-1][m-1] << "\n"; // 최종 위치의 값 출력(최종 이동 횟수 출력)
    return 0;
}
