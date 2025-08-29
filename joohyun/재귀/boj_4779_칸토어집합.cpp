/*
    https://www.acmicpc.net/problem/4779
    재귀를 이용하여 푼다.
*/
#include <iostream>
#include <string>
using namespace std;

// 집합, 시작 인덱스, 끝 인덱스
// 가운데 제거 후 처음과 끝은 재귀로 호출
// 그 전에 크기가 3이면 종료
void cantor_set(string& arr, int p, int q) {
    if (p == q) return; // 크가기 1이면 종료

    int a = (2 * p + q + 1) / 3; // 가운데 시작 인덱스 p + (q - p + 1) / 3
    int b = (p + 2 * q - 1) / 3; // 가운데 끝 인덱스 p + 2 * (q - p + 1) / 3 - 1
    for (int i = a; i <= b; i++) arr[i] = ' '; // 가운데 공백으로 바꾸기

    cantor_set(arr, p, a - 1); // 처음부분 칸토어
    cantor_set(arr, b + 1, q); // 끝 부분 칸토어
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int size = 1;

        if (n == 0) {
            cout << "-\n";
            continue;
        }

        for (int i = 0; i < n; i++) size *= 3;

        string arr(size, '-');

        cantor_set(arr, 0, size - 1);
        cout << arr << '\n';
    }

    return 0; 
}