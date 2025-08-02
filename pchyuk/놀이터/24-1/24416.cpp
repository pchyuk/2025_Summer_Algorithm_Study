#include <iostream>
using namespace std;
int f[41];
int fibo(int n){
    f[1] = f[2] = 1;
    for(int i=3; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fibo(n) << "\n" << n-2 << "\n";
    return 0;
}