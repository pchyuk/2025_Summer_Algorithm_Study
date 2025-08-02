#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int firm[n];
    for(int i=0; i<n; i++){
        scanf("%d", &firm[i]);
    }
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=0; j<n; j++){
            if(firm[i]<firm[j]) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}