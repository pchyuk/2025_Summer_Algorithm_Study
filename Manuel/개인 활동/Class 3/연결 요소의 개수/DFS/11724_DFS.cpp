#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for(int v : graph[u])
    {
        if(!visited[v])
        {
            dfs(v);
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

    int connnected_count = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            connnected_count++;
            dfs(i);
        }
    }

    cout << connnected_count << endl;
    return 0;
}