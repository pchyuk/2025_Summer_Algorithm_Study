#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

void dfs(const vector<vector<int>>& graph, int v, vector<bool>& visited, vector<int>& result)
{
    visited[v] = true;
    result.push_back(v);
    for(int neighbour : graph[v])
    {
        if(!visited[neighbour])
        {
            dfs(graph, neighbour, visited, result);
        }
    }
}

void bfs(const vector<vector<int>>& graph, int v, vector<bool>& visited, vector<int>& result)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    result.push_back(v);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for(int neighbour : graph[current])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
                result.push_back(neighbour);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for(int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> dfs_visited(N + 1, false);
    vector<int> dfs_result;
    dfs(graph, V, dfs_visited, dfs_result);
    for(size_t i = 0; i < dfs_result.size(); i++)
    {
        cout << dfs_result[i] << (i == dfs_result.size() - 1 ? "" : " ");
    }
    cout << endl;

    vector<bool> bfs_visited(N + 1, false);
    vector<int> bfs_result;
    bfs(graph, V, bfs_visited, bfs_result);
    for(size_t i = 0; i < bfs_result.size(); i++)
    {
        cout << bfs_result[i] << (i == bfs_result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}