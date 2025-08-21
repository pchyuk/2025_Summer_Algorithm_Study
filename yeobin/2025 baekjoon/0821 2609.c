// 2025.08.21
// baekjoon 2609
// 최대공약수와 최소공배수
// https://www.acmicpc.net/problem/2609

#include <stdio.h>

// 숫자 두개 A, B 가 있다고 하고
// 두개를 동시에 G 라는 숫자로 나눴을 때
// a,b 라는 숫자가 나오고 더이상 동시에 나눠지는 숫자가 없을 때
// G 는 최대공약수이며 최소공배수를 L 이라고 했을 때
// 최소공배수 L = G * a * b 이다
// 따라서 최소공배수 L 은 (a * b) / 최대공약수 G 로 구할 수 있음

int max(int a, int b) //최소공배수를 구하는 함수
{
	int i, j; //i = 큰 수, j = 작은 수
	int temp = 0; //최소공배수

	j = (a < b) ? a : b; //a < b 라는 식이 옳으면 j는 a, 옳지 않으면 j는 b;

	for (i = 1; i <= j; i++) { //1부터 하나씩 커지면서 j까지 반복
		if (a % i == 0 && b % i == 0) //i가 a, b와 나누었을때 나머지가 모두 0이 었을 경우
			temp = i; //최소공배수는 i가 된다
		// 계속 반복함으로써 제일 작은 최소공배수 i를 결정하도록 함
	}

	return temp;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b); //두 개의 자연수를 입력받음

	printf("%d\n%d\n", max(a, b), (a * b) / max(a, b));
	//먼저 최대공약수를 출력하고 다음 줄에 최소공약수를 출력

	return 0;
}