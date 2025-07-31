// 나의 풀이 - 박찬혁
// 풀이 과정 : 이 문제는 분석해 보면 단순히 nCm 을 구해보는 문제이다.
// 조합을 구하는 방법은 여러 가지가 있는데, 그중에서도 파스칼의 삼각형을 이용하여 문제를 풀었다.
// 또한 재귀를 이용하여 문제를 풀 수도 있지만, 그러면 시간 초과가 발생하므로 dp를 이용하여 배열에 값을 저장해 나가는 방식으로 문제를 해결했다.

#include <stdio.h>

int num[31][31];
int combi(int m, int n){
    for(int i=1; i<=m; i++){
        num[i][0] = 1; // nC0의 값은 항상 1이다. 
        num[i][1] = i; // nC1의 값은 항상 n이다.
        num[i][i] = 1; // nCn의 값은 항상 1이다.
    }
    for(int i=3; i<=m; i++){
        for(int j=2; j<i; j++){
            num[i][j] = num[i-1][j-1] + num[i-1][j]; // nCr = n-1Cr-1 + n-1Cr
        }
    }
    return num[m][n]; // 결과값 반환
}

int main(){
    int t;
    int n, m;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d %d", &n, &m);
        printf("%d\n", combi(m, n)); // 결과 출력
    }
    return 0;
}
