/* 나의 풀이 - 박찬혁 */
/* 풀이과정 : 주어진 조건에 따라 경우의 수를 나열하다 보면, 이 문제는 피보나치 수열을 구현하는 문제라는 것을 알게 된다. 
dp 방식으로 수열을 구현한 후, 각각의 결과값에서 15746을 나눈 나머지를 저장해 주면 된다. */
/* 사용된 알고리즘 : 다이나믹 프로그래밍(DP) */
/* 링크 : https://www.acmicpc.net/problem/1904 */

#include <iostream>
using namespace std;
int fibo[1000001]; // 피보나치 수열을 저장할 정수형 배열

// 피보나치 수열 알고리즘, 코드의 핵심 부분
int tile(int n){
    fibo[1] = 1; 
    fibo[2] = 2;
    for(int i=3; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2]; // dp 방식으로 피보나치 수열 구현
        fibo[i] %= 15746; // 계산된 값에서 15746을 나눈 나머지를 저장
    }
    return fibo[n];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    // 위의 3줄은 C++에서 입출력 속도를 향상시켜주는 역할을 함.

    int n;
    cin >> n; // n 입력
    cout << tile(n) << "\n";
    return 0;
}
