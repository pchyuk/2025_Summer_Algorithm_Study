import sys
from collections import deque
sys.setrecursionlimit(10 ** 6)

def solve_bfs():
    n = int(input())
    graph = [[] for _ in range(n + 1)]

    for _ in range(n):
        data = list(map(int, input().split()))
        node = data[0]

        # -1이 나올 때까지 연결된 노드와 거리를 읽음
        i = 1
        while i < len(data) and data[i] != -1:
            connected_node = data[i]
            distance = data[i + 1]
            graph[node].append((connected_node, distance))
            i += 2
    
    def bfs(start):
        visited = [False] * (n + 1)
        queue = deque([(start, 0)])
        visited[start] = True

        farthest_node = start
        max_distance = 0

        while queue:
            current_node, current_distance = queue.popleft()

            if current_distance > max_distance:
                max_distance = current_distance
                farthest_node = current_node
            
            for next_node, edge_distance in graph[current_node]:
                if not visited[next_node]:
                    visited[next_node] = True
                    queue.append((next_node, current_distance + edge_distance))
        
        return farthest_node, max_distance

    farthest_from_1, _ = bfs(1)
    _, diametre = bfs(farthest_from_1)

    return diametre

print(solve_bfs())