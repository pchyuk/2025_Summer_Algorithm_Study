#include <iostream>
using namespace std;

int buddy[2001][2001];
int visited[2001];
void dfs(int n, int m){
    visited[m] = 1;
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && buddy[m][i]){
            dfs(n, i);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        buddy[a][b] = 1;
        buddy[b][a] = 1;
    }
    for(int i=0; i<n; i++){
        
    }
    dfs(n, 0);

    return 0;
}