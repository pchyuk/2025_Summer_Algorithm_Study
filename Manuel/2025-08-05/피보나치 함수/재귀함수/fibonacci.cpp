#include <iostream>
#include <vector>

using namespace std;

int fibonacci_recursive(int n, int& count_0, int& count_1)
/* 
    count_0과 count_1의 경우 참조로 전달되어 함수 내에서 값을 변경하면
    main 함수에 있는 원래 변수의 값이 변경됨
*/
{
    if(n == 0)
    {
        count_0++; // 0 출력 횟수 증가
        return 0;
    }
    else if(n == 1)
    {
        count_1++; // 1 출력 횟수 증가
        return 1;
    }
    else
    {
        /*
            n - 1과 n - 2의 호출 결과를 더하지만 반환값은 중요하지 않음.
            중요한 것은 재귀 호출이 발생되는 것. count_0, count_1가 업데이트되어야 함
        */
       return fibonacci_recursive(n - 1, count_0, count_1) + fibonacci_recursive(n - 2, count_0, count_1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // 테스트 케이스의 개수
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        // 각 테스트 케이스마다 0과 1의 출력 횟수 초기화
        int count0 = 0;
        int count1 = 0;

        fibonacci_recursive(N, count0, count1);

        cout << count0 << " " << count1 << "\n";
    }

    return 0;
}