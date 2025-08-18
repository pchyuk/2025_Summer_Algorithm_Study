import sys
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)
N, M = map(int, input().split())
current_selection = []

def solve():
    if len(current_selection) == M:
        print(*current_selection)
        return
    
    for i in range(1, N + 1):
        current_selection.append(i)
        solve()
        current_selection.pop()

solve()