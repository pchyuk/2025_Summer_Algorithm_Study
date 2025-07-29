import sys

def solve():
    dp = [[0, 0] for _ in range(41)]

    dp[0][0] = 1
    dp[0][1] = 0

    dp[1][0] = 0
    dp[1][1] = 1

    for i in range(2, 41):
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0]
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1]
    
    T = int(sys.stdin.readline())

    for _ in range(T):
        N = int(sys.stdin.readline())
        print(dp[N][0], dp[N][1])

solve()