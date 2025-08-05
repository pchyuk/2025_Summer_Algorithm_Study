#include <stdio.h>

int main() {
    
    int hour, min;

    scanf("%d %d", &hour, &min);

    min = min - 45; // 원래 설정된 알림시간 보다 45분 일찍 앞서는 시간 설정
    
    if (min < 0) {
        min = min + 60; // 입력된 시간(분)에서 45분을 뺐을때 음수값이라면 60분을 더하고
        hour = hour - 1; // 한 시간을 뺀다
        if (hour < 0) {
            hour = hour + 24; // 또한 0시인경우 1을 빼고 24시간을 더한다
        }
    }

    printf("%d %d", hour, min);

    return 0;
}
