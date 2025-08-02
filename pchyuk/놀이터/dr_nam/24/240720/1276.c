#include <stdio.h>
int main() {
    int n, sum=1;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        sum*=i;
    }
    printf("%d\n", sum);

    return 0;
}