// 나의 풀이 - 박찬혁

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, start, end, count = 0;
    int num[1000000] = {0};
    scanf("%d", &n);

    start = 1;
    end = count = n;

    for(int i=1; i<=n; i++){
        num[i] = i; // 카드를 1부터 n까지 순서대로 저장한다.
    }

    if(n == 1){ // 카드가 1장밖에 없다면
        printf("1\n"); // 남아있는 카드도 1장이므로 1을 출력하고
        return 0; // 프로그램을 정상 종료시킨다.
    }

    else if(n == 2){ // 카드가 2장이라면
        printf("2\n"); // 1을 버리고 2가 남았을 것이므로 2를 출력하고
        return 0; // 프로그램을 정상 종료시킨다.
    }

    while(count > 1){ // 카드가 1장 남을때까지 반복
        num[start] = 0; // 제일 앞에있는 배열의 값을 0으로 초기화시킨다.(제일 앞 카드를 버린다.)
        start++; // start값을 1 증가시킨다.(제일 앞 카드가 바뀌었다.)
        end++; // end값을 1 증가시킨다.(배열의 제일 뒤에 공간을 하나 추가한다.)
        count--; // count값을 1 감소시킨다.(카드의 개수가 1 줄어들었다 -> 카드 버리기 완료)
        num[end] = num[start]; // 제일 앞에 있는 카드를 제일 뒤로 옮긴다.
        num[start] = 0; // 위의 과정을 반복한다.
        start++;
    }

    printf("%d\n", num[start]); // 남아 있는 한 장의 카드의 번호를 출력한다.
    return 0;
}
