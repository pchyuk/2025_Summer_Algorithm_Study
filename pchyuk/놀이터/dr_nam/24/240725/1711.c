#include <stdio.h>
int main() {
    int x1,x2,x3,y1,y2,y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    if(x1<=x3 && x3<=x2 && y1<=y3 && y3<=y2){
        printf("충돌\n");
    }
    else printf("비충돌\n");
    return 0;
}