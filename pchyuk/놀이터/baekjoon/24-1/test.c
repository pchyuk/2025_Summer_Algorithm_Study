#include <stdio.h>
int l[101];
int main(){
    int n,t,c=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &l[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(l[j]>l[j+1]){
                t=l[j+1];
                l[j+1]=l[j];
                l[j]=t;
                c++;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}