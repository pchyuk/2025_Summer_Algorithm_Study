/*
dp[i][j]: i번째 물건까지 고려했을 때, 배낭의 허용 무게가 j일 때 얻을 수 있는 최대 가치 합
점화식:
- w[i] > j: 현재 물건 i를 배낭에 넣을 수 없는 경우
    i - 1번째 물건까지 고려했을 때와 최대 가치는 동일.
- w[i] <= j: i를 담을 수 있는 경우
    1. 현재 물건을 담지 않는 경우 (dp[i - 1][j])
    2. 현재 물건을 담는 경우: (dp[i - 1][j - w[i]] + V[i])
        현재 물건을 담았으므로, 남은 무게 w[i]에서 i - 1번째 물건까지 고려한 최대 가치에
        현재 물건의 가치를 더함
    이 두 가지 선택지 중 더 큰 값을 취한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> W(N + 1);
    vector<int> V(N + 1);
    for(int i = 1; i <= N; i++)
    {
        cin >> W[i] >> V[i];
    }

    // dp[i][j]는 i번째 물건까지 고려했을 때, 배낭의 허용 무게가 j일 때의 최대 가치
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    // DP 테이블 채우기
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            // 현재 물건(i)를 담을 수 없는 경우:
            if(W[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            // 담을 수 있는 경우:
            else
            {
                // 현재 물건을 담지 않는 경우와 담는 경우 중 더 큰 값 선택
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
        }
    }
    cout << dp[N][K] << endl;

    return 0;
}