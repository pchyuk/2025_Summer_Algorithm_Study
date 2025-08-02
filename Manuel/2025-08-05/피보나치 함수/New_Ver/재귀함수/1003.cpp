#include <iostream>
#include <chrono> // 시간 측정을 위한 헤더

#define endl "\n"

using namespace std;

// 0과 1이 호출되는 횟수를 저장할 구조체
struct Count
{
    int zero;
    int one;
};

// fibo(n)을 호출했을 때 0과 1의 호출 횟수를 기록
Count fibo(int n)
{
    if(n == 0)
    {
        return {1, 0};
    }
    else if(n == 1)
    {
        return {0, 1};
    }
    // n이 2 이상일 경우
    else
    {
        // fibo(n - 1)과 fibo(n - 2)의 결과를 재귀적으로 얻음
        Count n_minus_1 = fibo(n - 1);
        Count n_minus_2 = fibo(n - 2);

        Count result;
        result.zero = n_minus_1.zero + n_minus_2.zero;
        result.one = n_minus_1.one + n_minus_2.one;

        return result;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        
        // 시간 측정 시작
        auto start = chrono::high_resolution_clock::now();

        Count result = fibo(N);

        // 시간 측정 종료
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;

        cout << result.zero << " " << result.one << endl;
        cout << "실행 시간: " << duration.count() << "ms" << endl;
    }
    return 0;
}
