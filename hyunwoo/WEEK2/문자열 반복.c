#include<stdio.h>

int main() {

	int testcase, r;
	char s[21];

	scanf("%d", &testcase);

	for (int i = 0;i < testcase;i++) {

		scanf("%d %s", &r, s);

		for (int j = 0;s[j]!='\0';j++) {
			for (int k = 0;k < r;k++) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
	
	
	return 0;

}