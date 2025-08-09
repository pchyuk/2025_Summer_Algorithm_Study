#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    while(true) {
        cin >> x >> y >> z;
        if (x + y + z == 0) break;

        if (x + y <= z || y + z <= x || z + x <= y) cout << "Invalid\n"; // !삼각형의 결정조건
        else if (x == y && y == z) cout << "Equilateral\n";
        else if (x != y && y != z && z != x) cout << "Scalene\n";
        else cout << "Isosceles\n";
    }

    return 0;
}