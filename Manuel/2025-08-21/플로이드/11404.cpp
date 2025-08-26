/*
플로이드-워셜 알고리즘: 경유지를 기준으로 최단 거리를 갱신하는 알고리즘
n개의 노드가 있고, 한 노드에서 다른 노드로 가는 간선이 있다. 각 간선에는 비용이 있다.
임의의 노드 A에서 B로 가는 가장 적은 비용을 구해야 한다.
같은 노드를 오가는 경우도 있고, 여러 간선을 통해 같은 노드를 오갈 수도 있다.

distance[i][j]: i번 도시에서 j번 도시까지의 최단 거리
k: 경유하는 도시

점화식:
distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
모든 노드 k를 순회하며 k를 거쳐 i에서 j로 가는 경로가 기존 경로보다 더 짧은지 확인한다.
기존 경로보다 더 짧다면 해당 경로를 distance[i][j]에 업데이트한다.
이 과정을 모든 i와 j에 대해 반복한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define endl "\n"

using namespace std;

const int INF = numeric_limits<int>::max();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 인접 행렬로 그래프 표현
    // distance[i][j]는 i에서 j로 가는 최단 거리
    vector<vector<int>> distance(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로 가는 경로는 0
    for(int i = 1; i <= n; i++)
    {
        distance[i][i] = 0;
    }

    // 초기 간선 정보 입력
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        distance[a][b] = min(distance[a][b], c);
    }

    // 플로이드-워셜 알고리즘
    // k: 경유지
    for(int k = 1; k <= n; k++)
    {
        // i: 출발지
        for(int i = 1; i <= n; i++)
        {
            // j: 도착지
            for(int j = 1; j <= n; j++)
            {
                // 거리가 무한대가 아닐 때만 (간선이 연결된 경우만) 계산
                if(distance[i][k] != INF && distance[k][j] != INF)
                {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    // 결과 출력
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(distance[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}