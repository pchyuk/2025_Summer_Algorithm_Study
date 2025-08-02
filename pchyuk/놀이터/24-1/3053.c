#include <stdio.h>
#define PI 3.14159265358979
int main(){
    int r;
    scanf("%d", &r);
    double circle = r*r*PI;
    double taxi = r*r*2;

    printf("%.6lf\n%.6lf\n", circle, taxi);
    return 0;
}