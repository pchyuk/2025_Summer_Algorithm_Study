#include <iostream>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c){
    if (a <= 0 || b <= 0 || c <= 0) // 첫 번째 조건
		return 1;

	if (a > 20 || b > 20 || c > 20) // 두 번째 조건
		return w(20, 20, 20);

	if (dp[a][b][c])
		return dp[a][b][c];

	if (a < b && b < c) // 세 번째 조건
	{
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return dp[a][b][c];
	}

	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); // 나머지 조건
	return dp[a][b][c];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c;

    while(1){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}