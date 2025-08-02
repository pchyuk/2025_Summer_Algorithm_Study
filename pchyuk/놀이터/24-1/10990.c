#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n-1; i++){
        printf(" ");
    }
    printf("*\n");

    for(int i=0; i<n-1; i++){
        for(int j=n-i-2; j>0; j--){
            printf(" ");
        }
        printf("*");
        for(int j=0; j<2*i+1; j++){
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}