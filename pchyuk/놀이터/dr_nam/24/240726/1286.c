#include <stdio.h>
int main() {
    int max=-1000000, min=1000000;
    int a;
    for(int i=0; i<5; i++){
        scanf("%d", &a);
        if(max<a) max=a;
        if(min>a) min=a;
    }
    printf("%d\n%d\n", max, min);
    return 0;
}