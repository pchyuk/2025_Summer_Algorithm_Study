/* 나의 풀이 - 박찬혁 */
/* 풀이과정 : 문제에서 주어진 대로 변형된 피보나치 수열을 dp 방식으로 구현한다. 
한 가지 유의사항은, koong 함수의 반환값을 int형으로 할 경우 오버플로우가 발생하기 때문에 
더 큰 수를 반환할 수 있도록 반환형을 long long으로 한다. */
/* 사용된 알고리즘 : 다이나믹 프로그래밍(dp) */
/* 링크 : https://www.acmicpc.net/problem/9507 */

#include <iostream>
using namespace std;
long long fib[70]; // 피보나치 수열을 저장할 배열. 큰 수가 저장되므로 long long형으로 한다.
long long koong(int n){
    fib[0] = 1;
    fib[1] = 1; 
    fib[2] = 2;
    fib[3] = 4;
    // 재귀 방식으로 피보나치를 70번째까지 구현하면 시간 초과가 발생하므로
    // 배열을 이용해서 이전의 값을 계산하여 저장해두는 방식으로 구현한다.
    for(int i=4; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2] + fib[i-3] + fib[i-4];
    }
    return fib[n];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        cout << koong(n) << "\n"; // 답 출력
    }
}
