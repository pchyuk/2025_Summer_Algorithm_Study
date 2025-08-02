#include <stdio.h>
int main() {
    int a, b;
    char x,p;
    double res;
    scanf("%d%c%c%d", &a,&x,&p,&b);
    if(p=='+'){
        res = -(double)b/(double)a;
        printf("%.2lf\n", res);
    }
    else if(p=='-'){
        res = (double)b/(double)a;
        printf("%.2lf\n", res);
    }

    return 0;
}