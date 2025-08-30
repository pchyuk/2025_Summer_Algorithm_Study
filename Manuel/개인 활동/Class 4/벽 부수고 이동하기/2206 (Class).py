from collections import deque

class Point:
    def __init__(self, x, y, dist, wall_broken):
        self.x = x
        self.y = y
        self.dist = dist
        self.wall_broken = wall_broken

def solve_class():
    n, m = map(int, input().split())
    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().strip())))
    
    queue = deque([Point(0, 0, 1, 0)])
    visited = [[[False] * 2 for _ in range(m)] for _ in range(n)]
    visited[0][0][0] = True

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    while queue:
        current = queue.popleft()

        if current.x == n - 1 and current.y == m - 1:
            return current.dist
        
        for i in range(4):
            nx = current.x + dx[i]
            ny = current.y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == 0:
                    if not visited[nx][ny][current.wall_broken]:
                        visited[nx][ny][current.wall_broken] = True
                        queue.append(Point(nx, ny, current.dist + 1, current.wall_broken))
                else:
                    if current.wall_broken == 0 and not visited[nx][ny][1]:
                        visited[nx][ny][1] = True
                        queue.append(Point(nx, ny, current.dist + 1, 1))
    return -1

print(solve_class())