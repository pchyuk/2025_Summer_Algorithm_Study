import sys

def factorial(n):
    dp = [0] * (n + 1)

    if n >= 0:
        dp[0] = 1
    if n >= 1:
        dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] * i
    
    return dp[n]

N = int(sys.stdin.readline())
print(factorial(N))
