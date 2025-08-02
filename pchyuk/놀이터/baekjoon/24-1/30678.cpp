#include <iostream>
using namespace std;

int board[5][5] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,1,1,1},
    {0,1,1,1,0},
    {0,1,0,1,0}
};

void star(int a, int b, int n){
    if(board[(a/n)%5][(b/n)%5] == 0) cout << " ";
    else {
        if(n==0) cout << "*";
        else star(a, b, n/5);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        sum *= n;
    }

    for(int i=0; i<sum; i++){
        for(int j=0; j<sum; j++){
            star(i, j, n+1);
        }
        cout << "\n";
    }
    
    return 0;
}