#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

long long dp[21]; // DP 배열. N의 최대값 20에 맞춰 크기를 21로 선언함.

void factorial(int n)
{
    // 초깃값 설정
    dp[0] = 1;
    dp[1] = 1;

    // 2부터 N까지 반복하여 값 계산
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    factorial(N);
    cout << dp[N] << endl;
    
    return 0;
}