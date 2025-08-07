import sys
from collections import deque

def solve():
    input = sys.stdin.readline

    M, N = map(int, input().split())
    box = []
    q = deque()
    unripe_tomatoes = 0

    for i in range(N):
        row = list(map(int, input().split()))
        box.append(row)
        for j in range(M):
            if row[j] == 1:
                q.append((i, j, 0))
            elif row[j] == 0:
                unripe_tomatoes += 1
    
    if unripe_tomatoes == 0:
        print(0)
        return
    
    max_time = 0

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    while q:
        x, y, time = q.popleft()
        max_time = time

        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]

            if 0 <= new_x < N and 0 <= new_y < M and box[new_x][new_y] == 0:
                box[new_x][new_y] = 1
                unripe_tomatoes -= 1
                q.append((new_x, new_y, time + 1))
    
    if unripe_tomatoes == 0:
        print(max_time)
    else:
        print(-1)

solve()