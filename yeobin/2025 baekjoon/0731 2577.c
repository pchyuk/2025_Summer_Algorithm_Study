// 2025.07.31
// baekjoon 2577
// 숫자의 개수
// https://www.acmicpc.net/problem/2577

#include <stdio.h>

int main()
{
	int a, b, c;
	int sum, num;
	int arr[10] = { 0 }; //숫자 0부터 9까지에 대한 배열

	scanf("%d\n%d\n%d", &a, &b, &c);

	sum = a * b * c; //A x B x C 의 값

	while (sum > 0)
	{
		num = sum % 10; //10으로 나누었을 때의 나머지, 현재 숫자에서의 1의 자리 숫자
		arr[num]++; //현재 1의 자리 숫자에 해당하는 숫자의 총 개수를 하나 늘리기
		sum /= 10; //아까 구한 1의 자리 숫자를 제외한 나머지 숫자를 다음 반복문에 사용
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]); //1부터 9까지의 숫자가 각각 몇 번 쓰였는지 출력
	}

	return 0;
}
