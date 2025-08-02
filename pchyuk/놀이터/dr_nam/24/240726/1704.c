#include <stdio.h>
int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    switch(b/1000000){
    case 1:
        printf("%d M\n", 2012-(a/10000+1900)+1);
        break;
    case 2:
        printf("%d F\n", 2012-(a/10000+1900)+1);
        break;
    case 3:
        printf("%d M\n", 2012-(a/10000+2000)+1);
        break;
    case 4:
        printf("%d F\n", 2012-(a/10000+2000)+1);
        break;
    }

    return 0;
}