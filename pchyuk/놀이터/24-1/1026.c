#include <stdio.h>
#include <stdlib.h>
int A[50];
int B[50];

int compare1(const void* first, const void* second){
    int* a = (int*)first;
    int* b = (int*)second;
    if(*a>*b) return 1;
    else if(*a<*b) return -1;
    else return 0;
}

int compare2(const void* first, const void* second){
    int* a = (int*)first;
    int* b = (int*)second;
    if(*a>*b) return -1;
    else if(*a<*b) return 1;
    else return 0;
}

int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &B[i]);
    }

    qsort(A, n, sizeof(int), compare1);
    qsort(B, n, sizeof(int), compare2);

    for(int i=0; i<n; i++){
        sum += A[i]*B[i];
    }

    printf("%d\n", sum);
    return 0;
}