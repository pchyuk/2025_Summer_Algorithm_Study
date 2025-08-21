#include <stdio.h>

int main() {
    int N;
    int arr[100];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        int num = arr[i];
        int prime = 1; // 소수라고 가정하자

        if (num < 2) {
            prime = 0; // 0 or 1은 소수가 아니다
        }
        else {
            for (int j = 2; j < num; j++) {
                if (num % j == 0) { // 자신을 제외한 수로 나누어 떨어진다면
                    prime = 0; // 소수가 아니다
                    break;
                }
            }
        }

        if (prime == 1) {
            count++; // 만약 소수라면 카운팅
        }
    }

    printf("%d\n", count);

    return 0;
}
