import sys

sys.setrecursionlimit(10 ** 6)

def dfs(graph, visited, u):
    visited[u] = True

    for v in graph[u]:
        if not visited[v]:
            dfs(graph, visited, v)

def main():
    input = sys.stdin.readline

    N, M = map(int, input().split())
    graph = [[] for _ in range(N + 1)]
    visited = [False] * (N + 1)

    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    
    connected_count = 0

    for i in range(1, N + 1):
        if not visited[i]:
            connected_count += 1
            dfs(graph, visited, i)
    print(connected_count)

main()