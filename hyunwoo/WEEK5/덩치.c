#include <stdio.h>

int main() {
    
    int num;
    int wei[50];
    int hei[50];
    int place[50];

    scanf("%d", &num);

    for (int i = 0;i < num;i++) {
        scanf("%d %d", &wei[i], &hei[i]);
    }

    for (int i = 0;i < num;i++) {
        int count = 0;
        for (int j = 0;j < num;j++) {
            if (wei[j] > wei[i] && hei[j] > hei[i]) {
                count++;
            }
        }
        place[i] = count + 1;
    }

    for (int i = 0;i < num;i++) {
        printf("%d ", place[i]);
   }

    return 0;
}
