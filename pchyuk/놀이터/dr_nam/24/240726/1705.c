#include <stdio.h>
int main() {
    int a, cnt=0;
    scanf("%d", &a);
    if(a%10!=0 && (a%10)%3==0) cnt++;
    if((a/10)%10!=0 && ((a/10)%10)%3==0) cnt++;
    if((a/100)!=0 && (a/100)%3==0) cnt++;
    switch(cnt){
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
        printf("%d\n", a);
        break;
    }

    return 0;
}