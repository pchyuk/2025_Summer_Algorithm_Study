#include <stdio.h>
int main() {
    long long int n;
    scanf("%lld", &n);
    long long int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    if(sum%7==4) printf("Bad\n");
    else printf("Good\n");

    return 0;
}