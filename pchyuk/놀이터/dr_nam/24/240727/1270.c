#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if(n%10==0) printf("%d\n", n/10);
    else printf("%d\n", n/10+1);

    return 0;
}