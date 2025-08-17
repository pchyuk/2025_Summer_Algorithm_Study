#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        if(n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        // 스티커 점수
        vector<vector<int>> stickers(2, vector<int>(n));
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> stickers[i][j];
            }
        }

        vector<vector<int>> dp(2, vector<int>(n, 0));

        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];

        if(n > 1)
        {
            dp[0][1] = stickers[0][1] + dp[1][0];
            dp[1][1] = stickers[1][1] + dp[0][0];

            for(int i = 2; i < n; i++)
            {
                dp[0][i] = stickers[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
                dp[1][i] = stickers[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    }
    return 0;
}