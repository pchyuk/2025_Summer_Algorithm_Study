#include <iostream>
using namespace std;
long long t[36];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    t[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i-1; j++){
            t[i] += t[j]*t[i-j-1];
        }
    }

    cout << t[n] << "\n";
    return 0;
}