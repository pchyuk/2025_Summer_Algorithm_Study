#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n, x = 0, flag = 0; 
    cin >> n;
	for (int i = 0; i < n; i++) {
		int t; 
        cin >> t;
		x ^= t; 
        flag |= x > 1;
	}
	if (flag) cout << (!x ? "cubelover" : "koosaga") << '\n';
	else cout << (x ? "cubelover" : "koosaga") << '\n';
}