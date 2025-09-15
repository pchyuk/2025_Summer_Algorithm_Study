// 2025.09.10
// baekjoon 1259
// 팰린드롬수
// https://www.acmicpc.net/problem/1259

#include <stdio.h>
#include <string.h>

int main(){
    char num[6];
    int n;
    while (1)
    {
        scanf("%s", num);
        n = strlen(num);
        if (num[0] == '0'){
            printf("\n");
            break;
        }
        else if(n == 1){
            printf("yes\n");
        }
        else if (num[0] == num[n - 1] && num[1] == num[n - 2])
        {
            printf("yes\n");
        }
        else
            printf("no\n");
        }
    return 0;
}