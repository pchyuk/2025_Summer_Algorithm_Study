/*
음수 간선 문제: 벨만-포드 알고리즘 사용
다익스트라는 양수 간선만 사용 가능.
동작 원리:
1. 거리 배열 0으로 초기화
2. N - 1번 반복하여 모든 간선에 대해 거리 갱신
3. N번째 반복에서도 갱신되면 음수 사이클이 있다는 의미 (계속 최단 거리가 갱신되므로 음수 간선이 있다는 뜻)
*/

#include <iostream>
#include <vector>
#include <climits>
#define endl "\n"

using namespace std;

struct Edge
{
    int from, to, cost;
    Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
};

bool hasNegativeCycle(int n, vector<Edge>& edges)
{
    // 거리 배열 초기화
    // 음수 사이클만 찾으면 되므로 시작접은 상관 없음
    vector<long long> dist(n + 1, 0);

    // n - 1번 반복
    for(int i = 0; i < n - 1; i++)
    {
        for(Edge& edge : edges)
        {
            if(dist[edge.from] != LLONG_MAX && dist[edge.from] + edge.cost < dist[edge.to])
            {
                dist[edge.to] = dist[edge.from] + edge.cost;
            }
        }
    }

    // n번째 반복에서도 거리가 갱신된다면 음수 사이클이 존재함
    for(Edge& edge : edges)
    {
        if(dist[edge.from] != LLONG_MAX && dist[edge.from] + edge.cost < dist[edge.to])
        {
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        vector<Edge> edges;
        
        // 도로 정보 입력(양방향)
        for(int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back(Edge(s, e, t));
            edges.push_back(Edge(e, s, t));
        }

        // 웜홀 정보 입력 (단방향, 음수 가중치)
        for(int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back(Edge(s, e, -t));
        }

        // 음수 사이클 존재 여부 확인
        if(hasNegativeCycle(n, edges))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}