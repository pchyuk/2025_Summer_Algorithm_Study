// 해시 맵으로 풀이
// 상근이가 가지고 있는 숫자를 key, 그 숫자의 개수를 value로 저장한다.
// 그리고 확인할 때 m개의 정수 각각마다 value가 뭔지 출력한다.
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // stdio와 동기화 해제
    cin.tie(nullptr); // cin, cout 연결 해제

    int n, m, x;
    unordered_map<int, int> card_counter; // 상근이의 카드 개수를 세는 해시 맵, 지동 0으로 초기화

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; // ex) (신규) x = 3 -> key : value = 3 : 0
        card_counter[x]++; // ex> key : value = 3 : 1
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x; // ex) x = 3
        cout << card_counter[x] << ' '; // ex) key : value = 3 : 1 에서 1출력
    }

    return 0;
}