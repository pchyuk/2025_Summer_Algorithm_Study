import sys
import heapq
from collections import defaultdict

def dijkstra(start, graph, n):
    dist = [float('inf')] * n
    dist[start] = 0

    pq = [(0, start)]

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    
    return dist

def main():
    input = sys.stdin.readline

    n, m, x = map(int, input().split())
    x -= 1
    graph = defaultdict(list)
    reverse_graph = defaultdict(list)

    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append((v, w))
        reverse_graph[v].append((u, w))
        
    dist_from_x = dijkstra(x, graph, n)
    dist_to_x = dijkstra(x, reverse_graph, n)
    max_time = 0

    for i in range(n):
        total_time = dist_to_x[i] + dist_from_x[i]
        max_time = max(max_time, total_time)
    
    print(max_time)

main()