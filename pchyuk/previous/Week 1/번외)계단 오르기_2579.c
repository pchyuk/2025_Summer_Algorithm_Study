// 2156번 포도주 시식과 비슷한 문제
// 포도주 문제의 경우, 마지막 잔을 무조건 마실 필요가 없지만, 
// 이 문제의 경우 마지막 계단을 반드시 밟아야 한다.

#include <stdio.h>
int stair[301];
int best[301]; // dp

int max(int a, int b){
    return a > b ? a : b; // 두 숫자 중 큰 값 반환
}

int main(){
    int n;

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &stair[i]);
    }

    best[1] = stair[1];
    best[2] = stair[1] + stair[2];

    // 포도주 문제와의 차이점
    // i번째 계단을 무조건 밟고, 3계단 연속으로 밟지 않도록 한다.
    for(int i=3; i<=n; i++){
        best[i] = stair[i] + max(best[i-2], best[i-3] + stair[i-1]);
    }

    printf("%d\n", best[n]);
    return 0;
}
