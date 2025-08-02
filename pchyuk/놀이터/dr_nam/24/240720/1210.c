#include <stdio.h>
int main() {
    int menu[5]={400, 340, 170, 100, 70};
    int a, b;
    int sum=0;
    scanf("%d %d", &a, &b);
    sum+=menu[a-1];
    sum+=menu[b-1];
    if(sum > 500) printf("angry\n");
    else printf("no angry\n");

    return 0;
}