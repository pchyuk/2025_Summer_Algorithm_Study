#include <iostream>
using namespace std;
int fibo[1000001];
int tile(int n){
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i=3; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= 15746;
    }
    return fibo[n];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << tile(n) << "\n";
    return 0;
}