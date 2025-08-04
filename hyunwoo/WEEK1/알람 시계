#include <stdio.h>

int main() {
    
    int hour, min;

    scanf("%d %d", &hour, &min);

    min = min - 45; 
    
    if (min < 0) {
        min = min + 60;
        hour = hour - 1;
        if (hour < 0) {
            hour = hour + 24;
        }
    }

    printf("%d %d", hour, min);

    return 0;
}
