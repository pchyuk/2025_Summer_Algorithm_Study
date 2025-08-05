import sys
from collections import deque

def bfs(graph, visited, start_node):
    q = deque([start_node])
    visited[start_node] = True
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)

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
            bfs(graph, visited, i)
    
    print(connected_count)

main()