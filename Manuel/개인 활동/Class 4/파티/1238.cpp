/*
핵심 아이디어:
여러 마을에서 X로 가려는 최단 경로를 구하려면 각각의 도시를 기준으로 다익스트라를 여러 번 실행해야 한다.
따라서 반대로 X에서 각 마을로 가는 최단 거리를 구하면 훨씬 효율적이다.
이때 역방향 그래프를 사용한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#define endl "\n"

using namespace std;

const int INF = 1e9;

// 다익스트라 알고리즘으로 시작점에서 모든 정점까지 최단 경로 구하기
vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 이미 처리된 정점이면 건너뜀
        if(d > dist[u])
            continue;
        
        // 인접한 모든 정점 확인
        for(auto& edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            // 더 짧은 경로를 발견한 경우
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;
    x--; // 0을 시작으로 하는 인덱스로 변환

    // 그래프와 역방향 그래프 생성
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<pair<int, int>>> reverse_graph(n);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 0을 시작으로 하는 인덱스로 변환
        u--;
        v--;
        graph[u].push_back({v, w});
        reverse_graph[v].push_back({u, w});
    }

    // X에서 모든 마을로의 최단 거리 (돌아가는 시간)
    vector<int> dist_from_x = dijkstra(x, graph);
    // 모든 마을에서 X로의 최단 거리 (X로 가는 시간)
    // 역방향 그래프에서 X를 시작점으로 다익스트라를 돌리면 원래 그래프에서 모든 정점에서 X로 가는 최단 거리와 같음
    vector<int> dist_to_x = dijkstra(x, reverse_graph);

    int max_time = 0;
    
    for(int i = 0; i < n; i++)
    {
        int total_time = dist_to_x[i] + dist_from_x[i];
        max_time = max(max_time, total_time);
    }

    cout << max_time << endl;

    return 0;
}