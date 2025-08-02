#include <stdio.h>
char a[100];
char b[100];
int main(){
    scanf("%s", a);
    for(int i=0; a[i] != '\0'; i++){
        b[i]=(a[i]*7)%80+48;
        a[i]+=2;
    }
    printf("%s\n%s\n", a, b);
    return 0;
}