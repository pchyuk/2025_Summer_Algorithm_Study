#include <stdio.h>
int main() {
    int n, a, count=0;
    scanf("%d", &n);
    a=n;
    if(a/100!=0 && (a/100)%3==0) count++;
    a%=100;
    if(a/10!=0 && (a/10)%3==0) count++;
    a%=10;
    if(a!=0 && a%3==0) count++;

    switch(count){
    case 1:
        printf("K\n");
        break;
    case 2:
        printf("KK\n");
        break;
    case 3:
        printf("KKK\n");
        break;
    default:
        printf("%d\n", n);
        break;
    }

    return 0;
}