/*
BFS / DFS를 두 번 실행
트리에서 임의의 점 A에서 가장 먼 노드는 반드시 지름의 한 쪽 끝 노드
지름의 한 쪽 끝 노드에서 가장 먼 노드는 반드시 지름의 다른 쪽 끝 노드
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl "\n"

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> graph;
bool visited[100001];

pair<int, int> bfs(int start, int n)
{
    /*
    start 노드에서 가장 먼 노드와 그 거리를 반환
    return: {가장 먼 노드, 최대 거리}
    */

    memset(visited, false, sizeof(visited));
    queue<pii> q;
    q.push(make_pair(start, 0));
    visited[start] = true;

    int farthest_node = start;
    int max_dist = 0;

    while(!q.empty())
    {
        int current_node = q.front().first;
        int current_dist = q.front().second;
        q.pop();

        if(current_dist > max_dist)
        {
            max_dist = current_dist;
            farthest_node = current_node;
        }

        for(int j = 0; j < graph[current_node].size(); j++)
        {
            pii edge = graph[current_node][j];
            int next_node = edge.first;
            int edge_dist = edge.second;

            if(!visited[next_node])
            {
                visited[next_node] = true;
                q.push(make_pair(next_node, current_dist + edge_dist));
            }
        }
    }

    return make_pair(farthest_node, max_dist);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    graph.resize(n + 1);

    // 트리 구성
    for(int i = 0; i < n; i++)
    {
        int node;
        cin >> node;

        int connected_node, dist;
        while(true)
        {
            cin >> connected_node;
            if(connected_node == -1)
            {
                break;
            }
            cin >> dist;
            graph[node].push_back(make_pair(connected_node, dist));
        }
    }

    // 1번 노드에서 가장 먼 노드 찾기
    pair<int, int> result1 = bfs(1, n);
    int farthest_from_1 = result1.first;

    // 그 노드에서 가장 먼 노드 찾기
    pair<int, int> result2 = bfs(farthest_from_1, n);
    int diametre = result2.second;

    cout << diametre << endl;

    return 0;
}