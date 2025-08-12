// 2025.08.05
// baekjoon 31403
// A+B-C
// https://www.acmicpc.net/problem/31403

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1001];
    char b[1001];
    int c;
    
    scanf("%s %s %d", a, b, &c);
    printf("%d\n", atoi(a) + atoi(b) - c);
    printf("%d\n", atoi(strcat(a,b)) - c);
    
    return 0;
}