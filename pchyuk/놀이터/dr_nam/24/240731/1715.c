#include <stdio.h>
int main() {
    int a,b,c;
    scanf("%d %d", &a, &b);
    int x=a;
    int y=b;
    while(x%y!=0){
        c=x%y;
        x=y;
        y=c;
    }
    printf("%d %d\n", a/c, b/c);
    return 0;
}