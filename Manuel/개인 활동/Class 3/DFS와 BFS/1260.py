import sys
from collections import deque

def dfs(graph, v, visited, result):
    visited[v] = True
    result.append(v)
    for neighbour in graph[v]:
        if not visited[neighbour]:
            dfs(graph, neighbour, visited, result)

def bfs(graph, v, visited, result):
    q = deque([v])
    visited[v] = True
    result.append(v)
    while q:
        current = q.popleft()
        for neighbour in graph[current]:
            if not visited[neighbour]:
                visited[neighbour] = True
                q.append(neighbour)
                result.append(neighbour)

def solve():
    N, M, V = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(N + 1)]

    for _ in range(M):
        n1, n2 = map(int, sys.stdin.readline().split())
        graph[n1].append(n2)
        graph[n2].append(n1)
    
    for i in range(1, N + 1):
        graph[i].sort()

    dfs_visited = [False] * (N + 1)
    dfs_result = []
    dfs(graph, V, dfs_visited, dfs_result)
    print(*dfs_result)

    bfs_visited = [False] * (N + 1)
    bfs_result = []
    bfs(graph, V, bfs_visited, bfs_result)
    print(*bfs_result)

solve()