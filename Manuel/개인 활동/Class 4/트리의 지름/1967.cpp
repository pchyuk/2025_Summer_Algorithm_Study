/*
1. 임의의 한 노드 A에서 가장 멀리 있는 노드 B를 찾는다. 이를 위해 A에서 시작하여 모든 노드까지의 거리를 계산하는
BFS 또는 DFS를 한 번 수행한다.
2. 노드 B에서 가장 멀리 있는 노드 C를 찾는다.
3. B와 C 사이의 거리가 트리의 지름이다.
    - 트리의 지름을 이루는 두 노드 중 하나는 반드시 임의의 한 노드에서 가장 멀리 떨어져 있기 때문이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<pair<int, int>> adj[100001];
vector<bool> visited;
int max_dist = 0;
int max_node = 0;

// DFS를 사용하여 시작 노드에서 가장 먼 노드를 찾음:
void dfs(int current_node, int current_dist)
{
    visited[current_node] = true;

    // 현재까지의 최대 거리를 갱신
    if(current_dist > max_dist)
    {
        max_dist = current_dist;
        max_node = current_node;
    }

    for(const auto& edge: adj[current_node])
    {
        int next_node = edge.first;
        int weight = edge.second;

        if(!visited[next_node])
        {
            dfs(next_node, current_dist + weight);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if(N == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 양방향에 간선 추가
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 1. 임의의 한 노드(1번)에서 가장 먼 노드를 찾음
    visited.assign(N + 1, false);
    dfs(1, 0);

    // 2. 가장 먼 노드(max_node)에서 다시 가장 먼 노드를 찾음
    visited.assign(N + 1, false);
    max_dist = 0; // 거리 초기화
    dfs(max_node, 0);

    cout << max_dist << endl;

    return 0;
}