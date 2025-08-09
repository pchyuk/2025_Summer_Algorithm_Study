#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n), y(n); // 0으로 초기화

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int w = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
    int h = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());

    cout << w * h;
    return 0;
}