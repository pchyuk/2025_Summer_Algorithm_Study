#include <iostream>
using namespace std;
void star(int x, int y, int n){
    if((x / n) % 3 == 1 && (y / n) % 3 == 1) cout << " ";
    else {
        if(n / 3 == 0) cout << "*";
        else star(x, y, n/3);
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            star(i, j, n);
        }
        cout << "\n";
    }
    return 0;
}