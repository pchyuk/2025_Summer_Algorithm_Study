import sys
from collections import deque
input = sys.stdin.readline

def solve():
    M, N, H = map(int, input().split())
    box = []
    q = deque()
    unripe_tomatoes = 0
    for z in range(H):
        floor = []
        for x in range(N):
            row = list(map(int, input().split()))
            floor.append(row)
            for y in range(M):
                if row[y] == 1:
                    q.append((z, x, y, 0))
                elif row[y] == 0:
                    unripe_tomatoes += 1
        box.append(floor)


    if unripe_tomatoes == 0:
        print(0)
        return

    max_time = 0

    dz = [0, 0, 0, 0, 1, -1]
    dx = [0, 0, 1, -1, 0, 0]
    dy = [1, -1, 0, 0, 0, 0]

    while q:
        z, x, y, time = q.popleft()
        max_time = time
        for i in range(6):
            nz, nx, ny = z + dz[i], x + dx[i], y + dy[i]
            if 0 <= nz < H and 0 <= nx < N and 0 <= ny < M and box[nz][nx][ny] == 0:
                box[nz][nx][ny] = 1
                unripe_tomatoes -= 1
                q.append((nz, nx, ny, time + 1))
    
    if unripe_tomatoes == 0:
        print(max_time)
    else:
        print(-1)

solve()