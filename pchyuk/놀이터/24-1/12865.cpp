#include <iostream>
using namespace std;

int weight[101];
int value[101];
int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j >= weight[i]){
                if(dp[i-1][j] < dp[i-1][j-weight[i]] + value[i]){
                    dp[i][j] = dp[i-1][j-weight[i]] + value[i];
                }
                else dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}