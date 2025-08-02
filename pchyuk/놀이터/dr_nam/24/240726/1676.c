#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int b[n];
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<n; i++){
        int cnt=1;
        for(int j=0; j<n; j++){
            if(b[i]<b[j]) cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}