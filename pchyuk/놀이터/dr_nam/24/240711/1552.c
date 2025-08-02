#include <stdio.h>

double x;

double f(double x){
    return x-(int)x;
}

int main(){
    scanf("%lf", &x);
    printf("%.14lf\n", f(x));
}