#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);

    if (a[0] + a[1] > a[2]) // 삼각형일 경우 그대로 합을 출력
        cout << a[0] + a[1] + a[2];
    else // 삼각형이 아닐 경우 가장 긴 변은 나머지 둘의 합 -1
        cout << a[0] + a[1] + (a[0] + a[1] -1);

    return 0;
}