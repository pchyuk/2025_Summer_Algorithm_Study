import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N, M = map(int, input().split())
current_selection = []

def solve(start_num):
    if len(current_selection) == M:
        print(*current_selection)
        return
    
    for i in range(start_num, N + 1):
        current_selection.append(i)
        solve(i)
        current_selection.pop()

solve(1)