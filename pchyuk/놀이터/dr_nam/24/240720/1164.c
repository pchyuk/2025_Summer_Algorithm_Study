#include <stdio.h>
int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if(a<=170) printf("CRASH\n");
    else if(b<=170) printf("CRASH\n");
    else if(c<=170) printf("CRASH\n");
    else printf("PASS\n");

    return 0;
}