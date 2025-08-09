/*
    ax + by = c, dx + ey = f이면
    (bd - ae)y = ad - af (단, (x, y)가 유일하므로 (bd - ae) != 0)
    y = (cd - af) / (bd - ae)
    x = (c - by) / a or (f - ey) / d
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;

    y = (c * d - a * f) / (b * d - a * e);
    if (a != 0) x = (c - b * y) / a;
    else x = (f - e * y) / d;

    cout << x << ' ' << y;
    return 0;
}