#include <stdio.h>
int main() {
    int n,sum=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int a=0;
        for(int j=1; j<=i; j++){
            a+=j;
        }
        sum+=a;
    }
    printf("%d\n", sum);
    return 0;
}