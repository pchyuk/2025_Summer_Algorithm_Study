#include<stdio.h>
int transform(int m, int n) {
	int temp;
	temp = m;
	m = n;
	n = temp;
	return 0;
}

int gcb(int a, int b) {

	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int lcb(int c, int d) {
	return (c * d) / gcb(c, d);
}

int main() {

	int x, y;

	scanf("%d %d", &x, &y);

	transform(x, y);

	int result1 = gcb(x, y);
	int result2 = lcb(x, y);

	printf("%d\n", result1);
	printf("%d", result2);

	return 0;

}
