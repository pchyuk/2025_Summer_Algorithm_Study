/*
    https://www.acmicpc.net/problem/11729
    재귀 + 스택으로 구현한다.
    a(n + 1) = a(n) + 1 + a(n)의 점화식을 이용한다.
*/
#include <iostream>
#include <stack>
using namespace std;

stack<int> s[3]; // 하노이탑 3개

// a번째 탑에서 b번째 탑으로 n개를 옮긴다.
void hanoi(int n, int a, int b) {
    if (n == 1) {
        s[b].push(s[a].top());
        s[a].pop();
        cout << a + 1 << ' ' << b + 1 << '\n';
        return;
    }

    hanoi(n - 1, a, 3 - a - b); // n - 1개를 출발지에서 목적지가 아닌 곳으로
    hanoi(1, a, b); // 맨 밑 1개를 출발지에서 목적지로
    hanoi(n - 1, 3 - a - b, b); // n - 1개를 목적지가 아닌 곳에서 목적지로
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;

    k  = (1 << n) - 1; // 옮긴 횟수 계산 후 출력
    cout << k << '\n';

    for (int i = n; i > 0; i--) { // 0번째 하노이에 원반 n개 저장
        s[0].push(i);
    }

    hanoi(n, 0, 2);

    return 0;
}