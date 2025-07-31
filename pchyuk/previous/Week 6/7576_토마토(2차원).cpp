#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m;
queue<pair<int, int>> q;

void BFS(){
    while(!q.empty()){
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = tmp_x + dr[i];
            int dy = tmp_y + dc[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m){
                if(box[dx][dy] == 0){
                    box[dx][dy] = box[tmp_x][tmp_y] + 1;
                    q.push({dx,dy});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    BFS();

    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(box[i][j] == 0){
                cout << "-1\n";
                return 0;
            }
            if(max < box[i][j]) max = box[i][j];
        }
    }

    if(max == 1) cout << "0\n";
    else cout << max - 1 << "\n";

    return 0;
}
