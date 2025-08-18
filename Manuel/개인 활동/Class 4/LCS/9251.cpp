#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();

    // dp[i][j]는 str1의 i번째 문자까지와 str2의 j번째 문자까지의 LCS 길이
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            // 두 문자가 같은 경우
            if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 두 문자가 다른 경우
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[len1][len2] << endl;

    return 0;
}