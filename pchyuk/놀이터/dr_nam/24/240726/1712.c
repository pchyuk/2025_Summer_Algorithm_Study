#include <stdio.h>
int main() {
    int a,b,k;
    scanf("%d %d %d", &a, &b, &k);
    int d=b-a;
    for(int i=a; i<=k; i+=d){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}