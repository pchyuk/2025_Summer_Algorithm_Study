#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; // n은 10억까지이므로 4n은 40억까지여서 int로 불가
    cin >> n;

    // 윗변과 밑변은 각각 n
    // n층이므로 좌우도 각각 n
    // 총 길이 4n
    cout << 4*n;
    return 0;
}