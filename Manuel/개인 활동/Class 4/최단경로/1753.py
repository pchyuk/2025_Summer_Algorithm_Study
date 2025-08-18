import sys
import heapq
input = sys.stdin.readline

def solve():
    V, E = map(int, input().split())
    start_node = int(input())
    adj = [[] for _ in range(V + 1)]
    for _ in range(E):
        u, v, w = map(int, input().split())
        adj[u].append((w, v))
    
    INF = float('inf')
    distance = [INF] * (V + 1)
    pq = []
    distance[start_node] = 0
    heapq.heappush(pq, (0, start_node))

    while pq:
        current_distance, current_node = heapq.heappop(pq)
        if current_distance > distance[current_node]:
            continue
        for next_distance, next_node in adj[current_node]:
            if distance[current_node] + next_distance < distance[next_node]:
                distance[next_node] = distance[current_node] + next_distance
                heapq.heappush(pq, (distance[next_node], next_node))
    
    for i in range(1, V + 1):
        if distance[i] == INF:
            sys.stdout.write("INF\n")
        else:
            sys.stdout.write(str(distance[i]) + "\n")

solve()