#include <stdio.h>

int num[31][31];
int combi(int m, int n){
    for(int i=1; i<=m; i++){
        num[i][0] = 1;
        num[i][1] = i;
        num[i][i] = 1;
    }
    for(int i=3; i<=m; i++){
        for(int j=2; j<i; j++){
            num[i][j] = num[i-1][j-1] + num[i-1][j];
        }
    }
    return num[m][n];
}

int main(){
    int t;
    int n, m;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d %d", &n, &m);
        printf("%d\n", combi(m, n));
    }
    return 0;
}