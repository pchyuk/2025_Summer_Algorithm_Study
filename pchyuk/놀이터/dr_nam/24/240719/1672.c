#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int num = n/k;
    if(num<=9999){
        for(int i=1; i<=num; i++){
            printf("F-%04d\n", i);
        }
    }
    else printf("번호 초과 오류\n");
    return 0;
}