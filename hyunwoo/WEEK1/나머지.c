//https://www.acmicpc.net/problem/3052

#include <stdio.h>

int main() {

	int a[10];
	int count[42] = { 0 }; // 0~41의 나머지 저장하기 위한 배열
	int rest;
	int b = 0;

	for (int i = 0;i < 10;i++) {
		scanf("%d", &a[i]);
		rest = a[i] % 42;
		count[rest]++; // 숫자를 나눈후 나온 나머지 표시
	}

	for (int i = 0;i < 42;i++) {
		if (count[i] >= 1) {
			b++; // 나머지 개수 세기
	}

	printf("%d", b);

	return 0;
}
