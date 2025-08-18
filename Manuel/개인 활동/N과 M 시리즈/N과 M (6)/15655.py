import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
current_selection = []

def solve(start_index):
    if len(current_selection) == M:
        print(*current_selection)
        return
    
    for i in range(start_index, len(nums)):
        current_selection.append(nums[i])
        solve(i + 1)
        current_selection.pop()

solve(0)