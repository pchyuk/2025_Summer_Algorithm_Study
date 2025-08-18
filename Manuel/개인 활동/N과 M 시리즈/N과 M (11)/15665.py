import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
current_selection = []

def solve():
    if len(current_selection) == M:
        print(*current_selection)
        return
    
    prev_num = 0

    for i in range(N):
        if nums[i] != prev_num:
            current_selection.append(nums[i])
            solve()
            current_selection.pop()
            prev_num = nums[i]

solve()