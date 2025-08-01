import sys
import time # 시간 측정을 위한 모듈

def fibo(n):
    # n이 0이면 0은 1번, 1은 0번 호출되므로 [1, 0] 반환
    if n == 0:
        return [1, 0]
    # 마찬가지의 경우
    elif n == 1:
        return [0, 1]
    # n이 2 이상일 경우
    else:
        n_minus_1 = fibo(n - 1)
        n_minus_2 = fibo(n - 2)
        
    zero_count = n_minus_1[0] + n_minus_2[0]
    one_count = n_minus_1[1] + n_minus_2[1]

    return [zero_count, one_count]

def solve():
    sys.setrecursionlimit(10 ** 6) # 재귀 깊이 제한을 늘림 (큰 수 입력용)

    T = int(sys.stdin.readline())
    for _ in range(T):
        N = int(sys.stdin.readline())

        start_time = time.perf_counter()

        result = fibo(N)

        end_time = time.perf_counter()

        print(f"{result[0]} {result[1]}")
        print(f"실행 시간: {(end_time - start_time) * 1000:.6f}ms")

solve()