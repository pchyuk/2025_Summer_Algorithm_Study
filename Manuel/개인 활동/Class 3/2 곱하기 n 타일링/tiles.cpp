#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1);

    if(n >= 0)
    {
        dp[0] = 1;
    }
    if(n >= 1)
    {
        dp[1] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] << "\n";
    return 0;
}