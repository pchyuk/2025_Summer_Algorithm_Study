#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> dp(11);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= 10; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i -3];
    }

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}