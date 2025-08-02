#include <iostream>
#include <vector>
#include <chrono>

#define endl "\n"

using namespace std;

struct Count
{
    int zero;
    int one;
};

// DP를 위한 전역 벡터
// dp[n]은 fibo(n) 호출 시 0과 1의 호출 횟수 저장
vector<Count> dp;

Count fibo(int n)
{
    if(dp[n].zero != -1) // 이미 계산된 값이 있으면 바로 반환 (왜 -1이 기준인지는 main 함수를 볼 것!)
    {
        return dp[n];
    }

    Count n_minus_1 = fibo(n - 1);
    Count n_minus_2 = fibo(n - 2);

    // 두 호출 횟수를 더하여 현재 fibo(n)의 호출 횟수를 계산
    dp[n].zero = n_minus_1.zero + n_minus_2.zero;
    dp[n].one = n_minus_1.one + n_minus_2.one;

    return dp[n];
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

        // dp 테이블 초기화. N의 최댓값이 40이므로 크기를 41로 설정.
        dp.assign(41, {-1, -1}); // -1로 초기화하여 아직 계산이 안 됐음을 표시
        dp[0] = {1, 0}; // fibo(0)의 기본 값
        dp[1] = {0, 1}; // fibo(1)의 기본 값

        auto start = chrono::high_resolution_clock::now();

        Count result = fibo(N);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;

        cout << result.zero << " " << result.one << endl;
        cout << "실행 시간: " << duration.count() << "ms" << endl;
    }
    return 0;
}
