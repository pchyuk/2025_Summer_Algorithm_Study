/*
    https://www.acmicpc.net/problem/27433

*/
/* sol1) for문 */
// #include <iostream>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int n;
//     cin >> n;
    
//     if (n == 0 || n == 1) cout << '1';
//     else {
//         long long fac = 1;
//         for (int i = 2; i <= n; ++i) {
//             fac *= i;
//         }
//         cout << fac;
//     }
    
//     return 0;
// }

/* sol2) 재귀 */
#include <iostream>
using namespace std;

// fac(n) = n * fac(n - 1)임을 이용하여 재귀로 작성
long long fac(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * fac(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << fac(n);

    return 0;
}