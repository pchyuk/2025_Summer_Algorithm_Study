#include <stdio.h>
int main() {
    int a, n;
    char b;
    scanf("%d %d %c", &a, &n, &b);
    for(int i=0; i<a; i++){
        if(b=='L'){
            for(int j=0; j<i; j++){
                printf(" ");
            }
        }
        else if(b=='R'){
            for(int j=0; j<a-i-1; j++){
                printf(" ");
            }
        }
        for(int k=0; k<n; k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}