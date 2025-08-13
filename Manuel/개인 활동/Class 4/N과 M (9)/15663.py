import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def solve():
    pass

N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
used = [False] * N
current = []

def solve():
    if len(current) == M:
        print(*current)
        return
    
    prev_num = 0
    for i in range(N):
        if not used[i] and nums[i] != prev_num:
            used[i] = True
            current.append(nums[i])
            prev_num = nums[i]
            solve()
            current.pop()
            used[i] = False

solve()