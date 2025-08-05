#include <stdio.h>
int main(){
    int n;
    int count = 0;
    scanf("%d", &n);
    int money = 1000 - n;

    while(money >= 500){
        money -= 500;
        count++;
    }
    while(money >= 100){
        money -= 100;
        count++;
    }
    while(money >= 50){
        money -= 50;
        count++;
    }
    while(money >= 10){
        money -= 10;
        count++;
    }
    while(money >= 5){
        money -= 5;
        count++;
    }
    while(money >= 1){
        money -= 1;
        count++;
    }

    printf("%d\n", count);
    return 0;
}