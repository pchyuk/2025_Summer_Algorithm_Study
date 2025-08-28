#include <stdio.h>

int main() {
    
    int n, k;
    int num[10001] = { 0 };

    scanf("%d", &n);

    for (int i = 0;i < n;i++) {
        scanf("%d", &k);
        num[k]++;
    }

    for (int i = 1;i <= 10000;i++) {
        while (num[i]--) {
            printf("%d\n", i);
        }
    }


    return 0;
}
