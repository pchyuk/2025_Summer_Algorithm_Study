#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, w, h, r[4], r_min = 1000;

    cin >> x >> y >> w >> h;
    
    r[0] = x;
    r[1] = y;
    r[2] = w - x;
    r[3] = h - y;

    for (auto x : r) {
        if (x < r_min)
            r_min = x;
    }
    
    cout << r_min;
    return 0;
}