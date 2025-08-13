#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n + 1, 0);
    queue<int> q;

    q.push(1);
    parent[1] = 1;
    
    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();
        for(int neighbour : adj[current_node])
        {
            if(parent[neighbour] == 0)
            {
                parent[neighbour] = current_node;
                q.push(neighbour);
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        cout << parent[i] << endl;
    }

    return 0;
}