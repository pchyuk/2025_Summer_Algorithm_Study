/*
    https://www.acmicpc.net/problem/18110
    난이도들을 입력받고 정렬을 한다.
    절사구간을 계산하고, 평균을 낸다.
    절사 구간 계산과 평균을 낼 때 반올림 함수를 이용한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> lev(n);
    for (int i = 0; i < n; i++) cin >> lev[i];
    if (n == 0) { // n = 0 예외
        cout << "0\n";
        return 0;
    }
    sort(lev.begin(), lev.end()); // 정렬

    int except = round((double)n * 0.15); // 제외할 15% 인원 수(반올림)
    int len = n - 2 * except; // 통계낼 인원 수(n = 0이면 0나와서 위에서 예외처리)
    int start = except, end = n - 1 - except; // 시작과 끝 인덱스

    // 절사 평균
    int sum = 0;
    for (int i = start; i <= end; i++) sum += lev[i];
    cout << round((double)sum / len) << '\n';

    return 0;
}