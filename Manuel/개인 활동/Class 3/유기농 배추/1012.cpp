#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define endl "\n"

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& field, vector<vector<bool>>& visited, int start_r, int start_c, int N, int M)
{
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while(!q.empty())
    {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int next_r = curr_r + dy[i];
            int next_c = curr_c + dx[i];

            if(next_r >= 0 && next_r < N && next_c >= 0 && next_c < M)
            {
                if(field[next_r][next_c] == 1 && !visited[next_r][next_c])
                {
                    visited[next_r][next_c] = true;
                    q.push({next_r, next_c});
                }
            }
        }
    }
}

void solve()
{
    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<int>> field(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for(int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        field[y][x] = 1;
    }

    int worm_count = 0;

    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            if(field[r][c] == 1 && !visited[r][c])
            {
                worm_count++;
                bfs(field, visited, r, c, N, M);
            }
        }
    }
    cout << worm_count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        solve();
    }

    return 0;
}