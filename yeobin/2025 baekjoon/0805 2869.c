//2025.08.05
// baekjoon 2869
// 달팽이는 올라가고 싶다
// https://www.acmicpc.net/problem/2869

#include <stdio.h>
int main()
{
    int A, B, V;
    // A == 낮에 올라가는 높이
    // B == 밤에 미끄러지는 높이
    // V == 나무 막대의 높이
    scanf("%d %d %d", &A, &B, &V); // 세 정수 A, B, V를 입력받음

    int n = 1; // n은 달팽이가 나무 막대를 올라가는 데 걸리는 날의 수를 나타냄, 처음에는 1일로 설정
    int sum = 0; // 달팽이가 총 올라간 높이를 저장하는 변수

    while (sum < V) // 달팽이가 총 올라간 높이가 나무 막대의 높이보다 작을 때까지 반복
    {
        sum += A; // 낮에 올라간 높이를 더함
        if(sum >= V) // 만약 달팽이가 총 올라간 높이가 나무 막대의 높이보다 크거나 같으면
            break; // 반복문 종료
        sum -= B; // 밤에 미끄러지는 높이를 뺌    
        n++; // 하루가 지나므로 n을 1만큼 증가시킴
    }

    printf("%d\n", n); // n의 값을 출력

    return 0;
}
//-> 시간초과 (반복문 사용 X)

#include <stdio.h>
int main()
{  
  int a,b,v,d;
  scanf("%d %d %d",&a,&b,&v);

  d = ( v - b - 1) / ( a - b) +1;
  // 실질적으로 하루에 달팽이가 올라가는 높이는 A-B 이므로
  // (V - B - 1) / (A - B) + 1을 통해 필요한 날 수를 계산
  
  printf("%d",d);

  return 0; 
}