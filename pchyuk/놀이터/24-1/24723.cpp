#include <iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    int sum = 1;
    cin >> n;
    for(int i=1; i<=n; i++){
        sum *= 2;
    }
    cout << sum << "\n";
    return 0;
}