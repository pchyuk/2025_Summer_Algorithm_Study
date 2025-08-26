#include <stdio.h>

int main() {
    
    int a;
    int score[1000];
    double sum = 0;
    double max = 0;

    scanf("%d", &a);
    
    for (int i = 0;i < a;i++) {
        scanf("%d", &score[i]);
        if (score[i] > max) max = score[i];
    }

    for (int i = 0;i < a;i++) {
        sum += (score[i] / max) * 100;
    }

    printf("%lf", sum / a);

    return 0;
}
