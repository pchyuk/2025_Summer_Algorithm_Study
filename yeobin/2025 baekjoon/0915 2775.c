// 2025.09.15
// baekjoon 2775
// 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775

#include <stdio.h>

int main()
{
    int t, k, n;
    int floor[15][15] = {0};
    for (int i = 1; i < 15; i++)
    {
        floor[0][i] = i;
    }

    for (int m = 1; m < 15; m++)
    {
        for (int j = 1; j < 15; j++)
        {
            floor[m][j] = floor[m][j - 1] + floor[m - 1][j];
        }
    }

    scanf("%d", &t);
    
    for (int i = 0; i < t; i++){
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", floor[k][n]);
    }
    return 0;
}