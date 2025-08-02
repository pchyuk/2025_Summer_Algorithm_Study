#include <stdio.h>
int main(){
    int b,c;
    scanf("%d", &b);
    scanf("%d", &c);
    int a[100];
    int count = b;

    while(c > 0){
        a[b-1] = c % 10;
        c /= 10;
        b--;
    }

    for(int i = 0; i < count; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}