/* 
    정렬 + 이진탐색으로 풀이
    상근이의 카드들을 모드 입력받은 후 정렬한다.
    이진탐색으로 원하는 숫자의 위치를 찾는 함수(lower_bound(), upper_bound())를 이용하여 개수를 구한다. 
   /\_/\
  ( o.o )
   > ^ <
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // stdio 동기화 해제
    cin.tie(nullptr); // cin, cout 연결 해제

    int n, m, x;
    cin >> n;
    vector<int> cards(n); // n칸의 정수형 벡터를 생성

    for (int i = 0; i < n; i++) {
        cin >> cards[i]; // i번째로 입력받은 카드의 숫자를 cards[i]에 저장
    }

    sort(cards.begin(), cards.end()); // cards를 처음부터 끝까지 크기순으로 정렬

    cin >> m;
    while (m--) {
        cin >> x; // 정렬된 벡터에서 x가 몇 개일지 찾아야 한다.
        auto lower = lower_bound(cards.begin(), cards.end(), x); // 반환형이 주소(vector<int>::iterator)라서 걍 auto로 함
        auto upper = upper_bound(cards.begin(), cards.end(), x); // 마지막으로 x가 나오는 다음 곳의 주소
        cout << (upper - lower) << ' '; // 그리서 걍 빼고 +1 안해도 됨
    }

    return 0;
}