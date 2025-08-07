#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int box[101][101][101];

int dr[] = {-1, 1, 0, 0, 0, 0}; 
int dc[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

queue<tuple<int, int, int>> q;

int m, n, h;

void BFS(){
    while(!q.empty()){
        int nx = get<0>(q.front());
        int ny = get<1>(q.front());
        int nz = get<2>(q.front());
        q.pop();

        for(int i=0; i<6; i++){
            int dx = nx + dr[i];
            int dy = ny + dc[i];
            int dz = nz + dh[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && dz >= 0 && dz < h){
                if(box[dx][dy][dz] == 0){
                    box[dx][dy][dz] = box[nx][ny][nz] + 1;
                    q.push({dx, dy, dz});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> h;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    BFS();

    int max = 0;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(box[i][j][k] == 0){
                    cout << "-1\n";
                    return 0;
                }
                if(max < box[i][j][k]) max = box[i][j][k];
            }
        }
    }

    if(max == 1) cout << "0\n";
    else cout << max - 1 << "\n";
    return 0;
}
