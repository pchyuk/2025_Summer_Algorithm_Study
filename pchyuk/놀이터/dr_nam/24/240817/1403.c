#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            printf("%d\n", a[j]);
        }
    }
    return 0;
}