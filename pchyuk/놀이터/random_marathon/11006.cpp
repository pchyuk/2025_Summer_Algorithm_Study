#include <iostream>
using namespace std;

int main(){
    int t;
    int n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << 2*m-n << " " << m - (2*m-n) << "\n";
    }
    return 0;
}