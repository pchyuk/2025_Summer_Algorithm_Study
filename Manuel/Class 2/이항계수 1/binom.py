import sys

N, K = map(int, sys.stdin.readline().split())

if K < 0 or K > N:
    print(0)
elif K == 0 or K == N:
    print(1)
else:
    if K > N // 2:
        K = N - K
    result = 1
    for i in range(K):
        result *= (N - i)
        result //= (i + 1)
    print(result)
