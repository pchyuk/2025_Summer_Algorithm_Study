// 2025.08.14
// baekjoon 10809
// 알파벳 찾기
// https://www.acmicpc.net/problem/10809

#include <stdio.h>
#include <string.h>
int main()
{
    char s[101]; // 입력한 문자열을 저장할 배열
    int arr[26]; // 알파벳 위치를 저장할 배열

    scanf("%s", s); // 문자열 입력

    for(int i = 0; i < 26; i++) // 알파벳 a-z에 대해 초기화
    {
        arr[i] = -1; // -1로 초기화하여 해당 알파벳이 등장하지 않았음을 표시
    }

    for (int i = 0; i<strlen(s); i++) // 문자열의 각 문자에 대해 반복
    {
        if (arr[s[i] - 'a'] == -1) // 해당 알파벳이 처음 등장한 경우
        // 'b'의 아스키코드 == 98, 'a'의 아스키코드 == 97
        // 이때 a==0, b==1, c==2, ..., z==25 이다
        // 따라서 'b' - 'a' == 1, 즉 알파벳 b에 해당하는 arr[1]에 위치를 저장하게 된다
        {
            arr[s[i] - 'a'] = i; // 위치 저장
        }
    }
    
    for (int i = 0; i < 26; i++) // 알파벳 a-z에 대해 반복
    {
        printf("%d ", arr[i]); // 위치 출력
    }

    return 0;
}