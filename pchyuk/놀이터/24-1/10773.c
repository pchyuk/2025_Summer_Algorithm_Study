#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int stack[MAX];
int top = -1;

int main(){
  int k, num;
  int sum = 0;
  scanf("%d", &k);
  for(int i=0; i<k; i++){
    scanf("%d", &num);
    if(num == 0){
      stack[top--] = 0;
    }
    else {
      stack[++top] = num;
    }
  }

  for(int i=0; i<=top; i++){
    sum += stack[i];
  }
  
  printf("%d\n", sum);
  return 0;
}