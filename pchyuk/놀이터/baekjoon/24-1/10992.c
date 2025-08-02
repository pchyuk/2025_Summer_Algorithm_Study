#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n-1; i++){
        printf(" ");
    }
    printf("*\n");

    for(int i=0; i<n-2; i++){
        for(int j=n-i-2; j>0; j--){
            printf(" ");
        }
        printf("*");
        for(int j=0; j<2*i+1; j++){
            printf(" ");
        }
        printf("*\n");
    }

    if(n > 1){
        for(int i=0; i<2*n-1; i++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}