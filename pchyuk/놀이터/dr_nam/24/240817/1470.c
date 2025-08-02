#include <stdio.h>
int a[100][100];
int main() {
    int n, d=1;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        if(i%2==0){
            for(int j=0; j<n; j++){
                a[j][i]=d++;
            }
        }
        else{
            for(int j=n-1; j>=0; j--){
                a[j][i]=d++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}