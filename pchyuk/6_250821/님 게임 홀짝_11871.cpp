#include <iostream>
using namespace std;

int main(){
    int n, p, result = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p;
        if(p%2 == 0) result ^= (p-2)/2;
        else result ^= (p+1)/2;
    }

    if(result = 0) cout << "cubelover\n";
    else cout << "koosaga\n";

    return 0;
}