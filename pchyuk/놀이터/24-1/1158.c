#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int count = n;
    int flag = 0;
    int index = 1;

    int* num = (int*)malloc((n+1)*sizeof(num));
    for(int i=1; i<=n; i++){
        num[i] = i;
    }

    printf("<");
    while(1){
        if(num[index] != 0){
            flag++;
            if(flag == k){
                printf("%d", num[index]);
                num[index] = 0;
                flag = 0;
                count--;
                if(count < 1) break;
                printf(", ");
            }
        }
        index++;
        if(index > n) index -= n;
    }
    printf(">\n");

    free(num);
    return 0;
}