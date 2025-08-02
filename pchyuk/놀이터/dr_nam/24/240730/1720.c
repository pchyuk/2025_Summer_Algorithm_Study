#include <stdio.h>
int main() {
    int n,a,b,c,res,min,flag=0,x,y;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d %d", &a, &b, &c, &res);
        if(a<b) min=a;
        else min=b;
        if(min>c) min=c;
        if(flag==0 && min!=res){
            x=i; y=min; flag=1;
        }
    }
    if(flag==0) printf("-1\n");
    else printf("%d %d\n", x, y);
    return 0;
}


