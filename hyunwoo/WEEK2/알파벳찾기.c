#include<stdio.h>

int main() {

    int alphabet[26]; // 알파벳 저장 배열
    char s[101]; //단어 저장 배열
    int a;

    scanf("%s", s);

    for (int i = 0; i < 26; i++) {
        alphabet[i] = -1; 
    }
    //알파벳 배열 -1로 초기화

    for (int i = 0;s[i] != '\0';i++) {
        a = s[i] - 'a'; // 해당되는 알파벳에 대한 인덱스
        if (alphabet[a] == -1) { 
            alphabet[a] = i; // 알파벳이 기록되지 않았을때의 경우에만 저장
        }
    }

    for (int i = 0;i < 26;i++) {
        printf("%d ", alphabet[i]);
    }

    return 0;

}
