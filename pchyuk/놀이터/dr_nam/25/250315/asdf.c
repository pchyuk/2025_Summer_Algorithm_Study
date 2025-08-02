#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    printf("%d초는 %d시간 %d분 %d초 입니다.\n", a, a/3600, a%3600/60, a%60);
    return 0;
}