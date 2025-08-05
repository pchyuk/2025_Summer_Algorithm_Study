//https://www.acmicpc.net/problem/8958
#include <stdio.h>

int main() {

	char word[81];
	int test;

	scanf("%d", &test); //케이스의 개수 입력

	for (int i = 0;i < test;i++) {
		scanf("%s", &word); //ox 문자열 입력

		int score = 0; // 총 점수
		int streak = 0; // 연속적인 o의 개수
		int j = 0;

		while (word[j] != '\0') { // 문자열이 끝날때까지
			if (word[j] == 'o') {
				streak++; // 연속적인 o의 개수 증가
				score = score + streak;
			}
			else {
				streak = 0; //x가 나온다면 streak 초기화
			}
			j++;
		}
		printf("%d\n", score);
	}

	return 0;

}
