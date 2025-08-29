/*
    https://www.acmicpc.net/problem/11651
    vector, pair을 이용한다.
    compare함수를 작성하여 sort의 세 번째 인자로 넣어준다.
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> coords(n);

    for (int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }

    sort(coords.begin(), coords.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << coords[i].first << ' ' << coords[i].second << '\n';
    }

    return 0;
}