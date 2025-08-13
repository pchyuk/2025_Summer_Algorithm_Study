#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

// 3차원 DP 배열. 최대 a, b, c가 20이므로 크기는 21 * 21 * 21.
vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21, 0)));

// 재귀함수 w(a, b, c)
int w(int a, int b, int c)
{
    // 1. a, b, c가 0 이하일 경우 (문제에서는 1부터 시작하므로 <= 0 조건은 0 이하를 포함)
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    // 2. a, b, c가 20 초과일 경우
    if(a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    } 
    // 3. 이미 계산된 값이 있다면 반환
    if(dp[a][b][c] != 0)
    {
        return dp[a][b][c];
    }
    // 4. a < b < c인 경우
    if(a < b && b < c)
    {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    }
    // etc.
    dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    while(true)
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
        {
            break;
        } 
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}