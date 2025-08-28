/*
    https://www.acmicpc.net/problem/10870
    fibo(n) = fibo(n - 1) + fibo(n - 2)  (n >= 2)
    fibo(1) = 1, fibo(0) = 0 임을 이용하여 재귀로 작성한다.
*/
/* sol1) for문 */
// #include <iostream>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     int fibo[3] = {0, 1, 1};
//     if (n < 3) cout << fibo[n];
//     else {
//         for (int i = 0; i < n - 2; ++i) {
//             fibo[0] = fibo[1];
//             fibo[1] = fibo[2];
//             fibo[2] = fibo[1] + fibo[0];
//         }
        
//         cout << fibo[2];
//     }

//     return 0;
// }

/* sol2) 재귀 */
#include <iostream>
using namespace std;

int fibo(int n) {
    if (n < 2) return n;
    else return fibo(n - 1) + fibo(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << fibo(n);

    return 0;
}