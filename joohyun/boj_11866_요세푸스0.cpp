/*
    큐를 이용하여 푼다.
    매번 k - 1 명의 사람들을 뒤로 보낸 후, k 번째 사람을 출력 후 pop한다.
    이를 큐가 빌때까지(n번) 반복하면 자연스럽게 요세푸스 순열 (n, k)가 출력된다.
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // stdio와 동기화를 끊는다.
    cin.tie(nullptr); // cin과 cout의 연결을 끊는다.

    int n, k;
    cin >> n >> k;

    queue<int> q; // 큐 만들고 1 ~ n 으로 초기화
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    while(!q.empty()) { // 큐가 빌때 까지 실행, 한 번 돌때마다 1개씩 없어짐
        for (int i = 0; i < k - 1; i++) { // k - 1개를 뒤로 이동
            q.push(q.front());
            q.pop();
        }
        
        // k 번째 제거
        cout << q.front();
        q.pop();

        if (!q.empty()) cout << ", ";
    }
    cout << ">" << '\n';
}