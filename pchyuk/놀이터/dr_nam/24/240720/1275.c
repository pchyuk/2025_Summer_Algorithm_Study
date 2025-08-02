#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for(int i=2; i<n; i++){
        if(n%i==0){
            printf("not prime\n");
            return 0;
        }
    }
    printf("prime\n");
    
    return 0;
}