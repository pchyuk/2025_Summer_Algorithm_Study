from collections import deque

def solve():
    n, m = map(int, input().split())
    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().strip())))
    
    queue = deque([(0, 0, 1, 0)])

    visited = [[[False] * 2 for _ in range(m)] for _ in range(n)]
    visited[0][0][0] = True

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while queue:
        x, y, dist, wall_broken = queue.popleft()

        if x == n - 1 and y == m - 1:
            return dist
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            if graph[nx][ny] == 0:
                if not visited[nx][ny][wall_broken]:
                    visited[nx][ny][wall_broken] = True
                    queue.append((nx, ny, dist + 1, wall_broken))
            else:
                if wall_broken == 0 and not visited[nx][ny][1]:
                    visited[nx][ny][1] = True
                    queue.append((nx, ny, dist + 1, 1))
    return -1

print(solve())