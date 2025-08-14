#include<stdio.h>

int main() {

	char num[6]; // 5자리수

	while (1) {
		scanf("%s", num);
		if (num[0] == '0' && num[1] == '\0') break; // 0을 입력한다면 종료

		int length = 0;
		int palindrome = 0;

		while (num[length] != '\0') { // 문자열의 자리수
			length++;
		}

		for (int i = 0;i < length / 2;i++) {
			if (num[i] != num[length - 1-i]) { // 입력한 수가 팰린드롬이 아닐때
				palindrome = 1;
				break;
			}
		}

		if (palindrome == 1) {
			printf("no\n"); // 팰린드롬이 아닐때 no 출력
		}
		else if (palindrome == 0) {
			printf("yes\n"); // 팰린드롬일때 yes 출력
		}

	}

	return 0;

}
