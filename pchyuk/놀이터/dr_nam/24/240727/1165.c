#include <stdio.h>
int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    if((90-a)%5==0){
        printf("%d\n", (90-a)/5+b);
    }
    else{
        printf("%d\n", (90-a)/5+b+1);
    }
    return 0;
}