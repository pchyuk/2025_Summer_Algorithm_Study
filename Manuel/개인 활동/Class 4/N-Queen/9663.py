import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N = int(input())
count = 0
is_col_used = [False] * N
is_right_used = [False] * (2 * N - 1)
is_left_used = [False] * (2 * N - 1)

def solve(row):
    global count
    
    if row == N:
        count += 1
        return
    
    for col in range(N):
        if not is_col_used[col] and not is_right_used[row + col] and not is_left_used[row - col + N - 1]:
            is_col_used[col] = True
            is_right_used[row + col] = True
            is_left_used[row - col + N - 1] = True

            solve(row + 1)

            is_col_used[col] = False
            is_right_used[row + col] = False
            is_left_used[row - col + N - 1] = False

solve(0)

print(count)