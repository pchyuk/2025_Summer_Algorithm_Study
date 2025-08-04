#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start_node)
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : graph[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int connected_count = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            connected_count++;
            bfs(i);
        }
    }

    cout << connected_count << endl;
    
    return 0;
}