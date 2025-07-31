/* 나의 풀이 - 박찬혁 */
/* 풀이과정 : 1차원 배열에 값을 계속 저장해 가면서(== DP) 
피보나치 함수의 값을 계산해 나간다. */
/* 사용된 알고리즘 : 다이나믹 프로그래밍(DP) */
/* 링크 : https://www.acmicpc.net/problem/1932 */

#include <stdio.h>
int fibo[41];

// 풀이 1: 재귀 함수. 보통 피보나치 함수를 구현하라 하면 이렇게 짜시겠죠?

// int fibonacci(int n) {
//     if (n == 0) { // n이 0이라면?
//         printf("0"); // 0 출력하고
//         return 0; // 0 반환
//     } else if (n == 1) { // n이 1이라면?
//         printf("1"); // 1 출력하고
//         return 1; // 1 반환
//     } else {
//         return fibonacci(n‐1) + fibonacci(n‐2); // 재귀 함수 호출. 이것도 틀리진 않습니다만...
//     }
// }

// 풀이 2: 다이나믹 프로그래밍(DP)

void fibonacci(int n){
    fibo[0] = 0; // 초기값 2개를
    fibo[1] = 1; // 배열에 저장해 두고
    for(int i=2; i<=n; i++){ // 2번째 값부터 for문을 돌리면서
        fibo[i] = fibo[i-1] + fibo[i-2]; // (중요!!) 1차원 "배열"에 값을 저장해 나간다.
        // 이렇게 하면 장점?
        // 재귀 함수를 사용할 때는 예를 들어서 
        // fibo(5)의 값을 알기 위해서는 fibo(4), fibo(3), fibo(2), fibo(1), fibo(0)의 값을
        // 전부 다시 "계산" 해야 하지만, (함수가 그만큼 많이 사용됨 == 시간이 오래 걸림)
        // 이 코드와 같이 계산한 값을 "배열에 저장"하게 된다면,
        // 더 이상 이전의 값을 계산할 필요 없이,
        // 그저 배열의 값을 찾아서 "읽어오기만" 하면 된다! (이게 DP입니다. 쉽죠?)
        // 새로 계산한 값도 자기 위치의 배열에 저장해 주면
        // 다음 값을 계산할 때 이전 값을 계산하지 않고 그저 값을 불러오면 끝.
    }
}

int main(){
    int t;
    int n;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d", &n);
        fibonacci(n);
        if(n==0) printf("1 0\n");
        else printf("%d %d\n", fibo[n-1], fibo[n]);
    }
    return 0;
}