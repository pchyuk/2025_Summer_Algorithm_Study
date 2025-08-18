import sys
input = sys.stdin.readline

def solve():
    if len(current_selection) == M:
        print(*current_selection)
        return
    
    for i in range(1, N + 1):
        if not used[i]:
            used[i] = True
            current_selection.append(i)
            solve()
            current_selection.pop()
            used[i] = False

sys.setrecursionlimit(10 ** 6)
N, M = map(int, input().split())
used = [False] * (N + 1)
current_selection = []

solve()