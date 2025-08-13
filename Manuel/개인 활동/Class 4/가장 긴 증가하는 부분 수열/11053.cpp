#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // 수열의 길이
    cin >> N;
    vector<int> A(N); // 수열 A
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    // dp[i]: i번째 원소를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이
    vector<int> dp(N, 1);
    // dp 채우기
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++) // i보다 1 작은 인덱스 j
        {
            // A[i]가 A[j]보다 크고, dp[i]가 dp[j] + 1보다 작으면 갱신
            if(A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열에서 가장 큰 값이 가장 긴 증가하는 부분 수열의 길이
    int max_length = 0;
    for(int len : dp)
    {
        if(len > max_length)
        {
            max_length = len;
        }
    }

    cout << max_length << endl;
    
    return 0;
}