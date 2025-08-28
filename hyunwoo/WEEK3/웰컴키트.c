#include <stdio.h>

int main() {
    
    int num;
    int tsize[6];
    int t, p;
    int tshirt = 0;

    scanf("%d", &num);

    for (int i = 0;i < 6;i++) {
        scanf("%d ", &tsize[i]);
    }

    scanf("%d %d", &t, &p);

    for (int i = 0;i < 6;i++) {
        if (tsize[i] > 0) {
            tshirt += (tsize[i] + t - 1) / t;
        }
    }

    int pen = num / p;
    int leftpen = num % p;

    printf("%d\n", tshirt);
    printf("%d %d", pen, leftpen);


    return 0;
}
