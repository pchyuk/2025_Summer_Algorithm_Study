#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int result = 0;
    for(int i=1; i<=n; i++){
        result = (result + k) % i;
    }
    cout << result + 1 << "\n";
    return 0;
}