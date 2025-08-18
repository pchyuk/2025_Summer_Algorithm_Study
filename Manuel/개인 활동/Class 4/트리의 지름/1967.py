import sys

def solve():
    sys.setrecursionlimit(10 ** 6)
    input = sys.stdin.readline

    N = int(input())
    if N == 1:
        print(0)
        return
    
    adj = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))
    
    max_dist = 0
    max_node = 0

    def dfs(current_node, current_dist, visited):
        nonlocal max_dist, max_node
        visited[current_node] = True

        if current_dist > max_dist:
            max_dist = current_dist
            max_node = current_node

        for next_node, weight in adj[current_node]:
            if not visited[next_node]:
                dfs(next_node, current_dist + weight, visited)
    
    visited = [False] * (N + 1)
    dfs(1, 0, visited)

    visited = [False] * (N + 1)
    max_dist = 0
    dfs(max_node, 0, visited)

    print(max_dist)

solve()