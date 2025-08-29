/*
    https://www.acmicpc.net/problem/14626
    문자열로 입력받고 짝수와 홀수를 나누어서 구한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    int k; // s에서 '*'의 인덱스 찾기
    for (int i = 0; i < 13; i++) {
        if (s[i] == '*') k = i;
    }
    
    int sum = 0; // 가중치 합을 구하기
    for (int i = 0; i < 13; i++) {
        if (s[i] == '*') continue;
        else if (i % 2 == 0) sum += s[i] - '0'; // 홀수번째는 그대로 합
        else sum += 3 * (s[i] - '0');
    }

    int check = (10 - sum % 10) % 10; // 회손된 수를 구하기 위해 식 정리
    // 나머지가 0일 때 10이 되는 예외 처리를 위해 %10을 한 번 더 한다
    int num; // 회손된 숫자 저장
    if (k % 2 == 0) { // 홀수번째(마지막 포함)
        num = check;
    }
    else { // 짝수번째
        while (true) { // 3의 배수가 될 때까지 10을 더해 간다
            if (check % 3 == 0) {
                num = check / 3;
                break;
            }
            else check += 10;
        }
    }

    cout << num;
    return 0;
}