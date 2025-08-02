#include <stdio.h>

long long int n;

long long int sqrt(long long int n){
    long long int count = 0;
    for(long long int i=1; i*i<=n; i++) count++;
    return count;
}

int main(){
    scanf("%lld", &n);
    printf("%d\n", sqrt(n));
    return 0;
}