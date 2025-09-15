// 2025.09.10
// baekjoon 1978
// 소수 찾기
// https://www.acmicpc.net/problem/1978

#include <stdio.h>

int main(){
    int n, arr[100];
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int a = 0;
        for (int j = 0; j < arr[i]; j++) {
            if (arr[i] % (j+1) == 0)
                a++;
        }
        if(a == 2)
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}