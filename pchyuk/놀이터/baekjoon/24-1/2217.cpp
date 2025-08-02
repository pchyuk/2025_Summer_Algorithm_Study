#include <iostream>
#include <algorithm>
using namespace std;
int rope[100001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> rope[i];
    }
    sort(rope, rope+n);
    int max = 0;
    for(int i=0; i<n; i++){
        max = max > rope[i] * (n-i) ? max : rope[i] * (n-i);
    }
    cout << max << "\n";
    return 0;
}