#include<stdio.h>

int main() {

	int test;

	scanf("%d", &test);

	for (int i = 0;i < test;i++) {


		int H, W, N;

		scanf("%d %d %d", &H, &W, &N);

		int floor = N % H;
		int room = N / H + 1;

		if (floor == 0) {
			floor = H;
			room = N / H;
		}

		printf("%d%02d\n", floor, room);
	}

	return 0;

}