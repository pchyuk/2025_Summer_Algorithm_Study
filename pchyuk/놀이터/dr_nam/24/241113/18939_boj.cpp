#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    int n, m, k;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n >> m >> k;
        if(max(n,m) < k*2) cout << "Yuto\n";
        else {
            if((n*m)%2==0) cout << "Platina\n";
            else cout << "Yuto\n";
        }
    }

    return 0;
}