#include<stdio.h>

int factorial(int n) {

	if (n <= 1) {
		return 1;
	}

	return n * factorial(n - 1);

}

int main() {

	int N, K;
	
	scanf("%d %d", &N, &K);

	printf("%d", factorial(N) / (factorial(K) * factorial(N - K)));
	
	return 0;

}