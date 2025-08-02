#include <stdio.h>
int level[101];
int main(){
    int n;
    int count = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &level[i]);
    }

    for(int i=n-1; i>0; i--){
        if(level[i] >= level[i+1]){
            count += level[i] - (level[i+1] - 1);
            level[i] = level[i+1] - 1;
        }
    }

    printf("%d\n", count);
    return 0;
}