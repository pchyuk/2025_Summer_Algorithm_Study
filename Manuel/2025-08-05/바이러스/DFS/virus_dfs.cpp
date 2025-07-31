#include <iostream>
#include <vector>

using namespace std;

/* DFS 탐색 함수 
graph: 인접 리스트로 표현된 그래프
visited: 방문 여부를 기록하는 벡터
current_com: 현재 탐색 중인 컴퓨터 번호
infected_count: 감염된 컴퓨터 수를 저장하는 변수
*/
void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int current_com, int& infected_count)
{
    visited[current_com] = true; // 현재 컴퓨터를 방문했다고 표시
    infected_count++; // 감염된 컴퓨터 수 증가

    for(int neighbour : graph[current_com]) // 현재 컴퓨터에 연결된 모든 이웃 컴퓨터 확인
    {
        if(!visited[neighbour]) // 이웃 컴퓨터를 방문하지 않았으면
        {
            dfs(graph, visited, neighbour, infected_count); // 이웃 컴퓨터를 대상으로 재귀적으로 연산 수행
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num_computers; // 컴퓨터의 수
    cin >> num_computers;
    int num_connections; // 네트워크로 연결된 컴퓨터 쌍의 수
    cin >> num_connections;

    // 그래프를 인접 리스트로 표현
    vector<vector<int>> graph(num_computers + 1); // 컴퓨터의 번호가 1부터 시작하므로 num_computers + 1 크기로 벡터 생성

    for(int i = 0; i < num_connections; i++) // 그래프에 연결 정보 추가
    {
        int c1, c2;
        cin >> c1 >> c2;
        // 쌍방향 연결이므로 양쪽에 모두 데이터 추가
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    vector<bool> visited(num_computers + 1, false); // 방문 여부를 기록하는 배열. 초기값은 모두 false.
    int count_infected = 0; // 감염된 컴퓨터 수

    dfs(graph, visited, 1, count_infected); // 1번 컴퓨터부터 DFS 탐색 시작.

    cout << count_infected - 1 << "\n"; // 1번 컴퓨터는 무조건 감염되므로 자신을 제외하고 감염된 컴퓨터 개수 출력

    return 0;
}