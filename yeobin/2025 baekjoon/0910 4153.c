// 2025.09.10
// baekjoon 4153
// 직각삼각형
// https://www.acmicpc.net/problem/4153

#include <stdio.h>
int main(){
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a==0 && b==0 && c==0)
            break;
        else if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}