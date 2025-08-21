#include <iostream>
using namespace std;

int main(){
    int n, p[1001], result = 0, ans = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p[i];
        result ^= p[i];
    }

    for(int i=0; i<n; i++){
        for(int j=1; j<=p[i]; j++){
            int tmp = p[i] - j;
            tmp ^= p[i];
            tmp ^= result;
            if(tmp == 0) ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}