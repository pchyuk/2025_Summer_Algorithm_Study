#include <iostream>
#include <vector>
#include <queue> // 큐를 사용하기 위한 헤더 파일

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_computers;
    cin >> num_computers;
    int num_connections;
    cin >> num_connections;
    
    // 그래프를 인접 리스트로 표현.
    vector<vector<int>> graph(num_computers + 1); // 컴퓨터 번호를 1부터 N까지 부여하기 때문에 num_computers + 1 크기로 벡터를 생성

    // 연결 정보 추가
    for(int i = 0; i < num_connections; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        // 양방향 연결이므로 양쪽에 정보 추가
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    // 방문 여부를 기록할 배열 생성
    // 초기값은 false
    vector<bool> visited(num_computers + 1, false);

    queue<int> q; // BFS를 위한 큐 생성
    q.push(1); // 시작점인 1번을 큐에 넣음
    visited[1] = true; // 방문 표기

    int count_infected = 0; // 바이러스에 걸린 컴퓨터 수

    while(!q.empty())
    {
        int current_computer = q.front(); // 큐의 맨 앞 컴퓨터 확인
        q.pop(); // 큐에서 컴퓨터를 빼냄

        for(int neighbour : graph[current_computer])
        {
            if(!visited[neighbour]) // 만일 이웃 컴퓨터를 방문하지 않았을 경우
            {
                visited[neighbour] = true; // 방문 표기
                q.push(neighbour); // 큐에 넣음
                count_infected++; // 감염된 컴퓨터의 수를 1 증가시킴
            }
        }
    }
    
    cout << count_infected << "\n";

    return 0;
}