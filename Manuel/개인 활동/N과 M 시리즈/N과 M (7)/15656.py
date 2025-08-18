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
    
    for i in range(N):
        current_selection.append(nums[i])
        solve()
        current_selection.pop()

solve()