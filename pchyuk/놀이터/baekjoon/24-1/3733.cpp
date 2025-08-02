#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    while(cin >> n >> s){
        cout << s/(n+1) << "\n";
    }

    return 0;
}