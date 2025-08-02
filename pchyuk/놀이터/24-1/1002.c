#include <stdio.h>
#include <math.h>

int main(){
    int t;
    int x1, y1, r1, x2 ,y2 ,r2, result;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
        int abs = r1 > r2 ? r1 - r2 : r2 - r1;
        if(distance == 0 && r1 == r2) result = -1;
        else if(r1 + r2 == distance || abs == distance) result = 1;
        else if(r1 + r2 > distance && abs < distance) result = 2;
        else result = 0;
        printf("%d\n", result);
    }
    return 0;
}