// 2025.08.05
// baekjoon 2920
// 음계
// https://www.acmicpc.net/problem/2920

#include <stdio.h>

int main()
{
	int num[8] = { 0 }; //숫자 1부터 8까지의 배열
	//0 == 'mixed'
	//1 == 'ascending'
	//2 == 'descending' 이라고 하면
	int a = 0; //처음에는 'mixed' 의 경우로 설정

	for (int i = 0; i < 8; i++) {
		scanf("%d", &num[i]); //8개 숫자를 순서대로 배열에 저장
	}

	//a == 1, 즉 'ascending'일 경우의 코드
	if (num[0] == 1) { //첫번째 배열의 숫자가 1일 때
		for (int i = 1; i < 8; i++) { //두번째부터 8번째까지의 배열 반복문
			if (num[i] == i + 1) { //배열이 0부터 시작하니까 배열 순서에 +1 한 숫자와 같으면
				a = 1; //1의 경우('ascending')로 바꾸기
			}
			else { //앞의 경우가 아닌 경우, 즉 배열의 숫자가 하나씩 커지지 않는 경우
				a = 0; //0의 경우('mixed')로 바꾸기
				break; //더이상 실행하지 않고 나가기
			}
		}
	}

	//a == 2, 즉 'descending'일 경우의 코드
	if (num[0] == 8) { //첫번째 배열의 숫자가 8일 때
		for (int i = 1; i < 8; i++) { //두번째부터 8번째까지의 배열 반복문
			if (num[i] == 8 - i) { //배열이 0부터 시작하니까 배열 순서를 8에서 뺀 숫자와 같으면
				a = 2; //2의 경우('descending')로 바꾸기
			}
			else { //앞의 경우가 아닌 경우, 즉 배열의 숫자가 하나씩 작아지지 않는 경우
				a = 0; //0의 경우('mixed')로 바꾸기
				break; //더이상 실행하지 않고 나가기
			}
		}
	}
	
	if (a == 1) {
		printf("ascending\n"); //a == 1일 경우 'ascending' 출력
	}
	else if (a == 2) {
		printf("descending\n"); //a == 2일 경우 'descending' 출력
	}
	else
		printf("mixed\n"); //a == 0일 경우 'mixed' 출력

	return 0;
}