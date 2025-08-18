#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define endl "\n"

using namespace std;

const int INF = numeric_limits<int>::max();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    int start_node;
    cin >> start_node;

    vector<vector<pair<int, int>>> adj(V + 1);
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    vector<int> distance(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[start_node] = 0;
    pq.push({0, start_node});

    while(!pq.empty())
    {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if(current_distance > distance[current_node])
        {
            continue;
        }

        for(const auto& edge : adj[current_node])
        {
            int next_distance = edge.first;
            int next_node = edge.second;

            if(distance[current_node] + next_distance < distance[next_node])
            {
                distance[next_node] = distance[current_node] + next_distance;
                pq.push({distance[next_node], next_node});
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        if(distance[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << distance[i] << endl;
        }
    }

    return 0;
}