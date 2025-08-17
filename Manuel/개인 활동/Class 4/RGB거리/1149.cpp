/*
DP 문제:
각 집(i)을 칠하는 최소 비용을 dp[i][색상]으로 정의한다.
점화식:
dp[i][0] (i번째 집을 빨강으로 칠할 때) = i번째 집을 빨강으로 칠하는 비용 + min(dp[i-1][1], dp[i-1][2])
(이전 집은 초록 혹은 파랑으로 칠해야 함)
dp[i][1] (i번째 집을 초록으로 칠할 때) = i번째 집을 초록으로 칠하는 비용 + min(dp[i-1][0], dp[i-1][2])
dp[i][2] (i번째 집을 파랑으로 칠할 때) = i번째 집을 파랑으로 칠하는 비용 + min(dp[i-1][0], dp[i-1][1])

마지막 N번째 집까지 이 과정을 반복하면 최종적으로
min(dp[N][0], dp[N][1], dp[N][2])가 모든 집을 칠하는 최소 비용이 됨.
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

    int n;
    cin >> n;
    // 각 집을 칠하는 비용을 저장:
    vector<vector<int>> costs(n, vector<int>(3));
    for(int i = 0; i < n; i++)
    {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    // DP: dp[i][j]는 i번째 집을 j색으로 칠하는 최소 비용
    vector<vector<int>> dp(n, vector<int>(3));
    // 첫 번째 집의 비용은 그대로 초기화:
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    // 두 번째 집부터 N번째 집까지 최소 비용 계산
    for(int i = 1; i < n; i++)
    {
        // i번째 집을 빨강으로 칠하는 최소 비용
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        // 초록, 파랑도 같은 원리로 진행
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    // N번째 집까지 칠했을 때의 최소 비용:
    int result = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << result << endl;

    return 0;
}