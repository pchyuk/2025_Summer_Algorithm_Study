import sys
from collections import deque

def solve():
    input = sys.stdin.readline

    n, m = map(int, input().split())
    grid = []
    distances = [[-1] * m for _ in range(n)]
    
    q = deque()
    
    target_r, target_c = -1, -1

    for i in range(n):
        row_data = list(map(int, input().split()))
        grid.append(row_data)
        for j in range(m):
            if row_data[j] == 2:
                target_r, target_c = i, j
    
    q.append((target_r, target_c))
    distances[target_r][target_c] = 0

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    while q:
        r, c = q.popleft()
        dist = distances[r][c]

        for i in range(4):
            new_r, new_c = r + dr[i], c + dc[i]
            
            if 0 <= new_r < n and 0 <= new_c < m:
                if grid[new_r][new_c] == 1 and distances[new_r][new_c] == -1:
                    distances[new_r][new_c] = dist + 1
                    q.append((new_r, new_c))
    
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                print(0, end = " ")
            else:
                print(distances[i][j], end = " ")
        print()

solve()