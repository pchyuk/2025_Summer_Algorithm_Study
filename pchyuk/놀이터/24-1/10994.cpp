#include <iostream>
using namespace std;
void star(int x, int y, int n){
    if(n%2==1){
        if(x==0 || y==0 || x==2*n-2 || y==2*n-2){
            cout << "*";
        }
        else star(x-1, y-1, n-1);
    }
    else {
        if(x==0 || y==0 || x==2*n-2 || y==2*n-2){
            cout << " ";
        }
        else star(x-1, y-1, n-1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0; i<4*n-3; i++){
        for(int j=0; j<4*n-3; j++){
            star(i,j,2*n-1);
        }
        cout << "\n";
    }
    return 0;
}