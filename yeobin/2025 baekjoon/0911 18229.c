// 2025.09.11
// baekjoon 18229
// 내가 살게, 아냐 내가 살게
// https://www.acmicpc.net/problem/18229

#include <stdio.h>

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int arr[101][101];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int sum[101] = {0};

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            sum[j] += arr[j][i];
            if (sum[j] >= k){
                printf("%d %d", j + 1, i + 1);
                return 0;
            }
        }
    }

    return 0;
}