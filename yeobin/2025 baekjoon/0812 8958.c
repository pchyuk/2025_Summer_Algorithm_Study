// 2025.08.12
// baekjoon 8958
// OX퀴즈
// https://www.acmicpc.net/problem/8958

#include <stdio.h>

int main()
{
    int n; // 테스트 케이스의 개수
    char ox[81]; // OX 문자열을 저장할 배열
    int a[81]; // OX 문자열의 점수를 저장할 배열
    scanf("%d", &n); // 테스트 케이스의 개수 입력

    for(int i=0; i<n; i++){
        scanf("%s", ox);
        
        int score = 0; // 총 점수
        int count = 0; // 연속적인 O의 개수

        for(int j=0; ox[j]!='\0'; j++){ // 문자열의 끝까지 반복
            if(ox[j] == 'O') // O가 나오면
            {
                count++; // O가 나오면 연속 카운트 증가
                score += count; // 현재 점수에 연속 카운트 더하기
            }
            else if(ox[j] == 'X') // X가 나오면
            {
                count = 0; // X가 나오면 연속 카운트 초기화
            }
        }
        printf("%d\n", score); // 최종 점수 출력
    }

    return 0;
}