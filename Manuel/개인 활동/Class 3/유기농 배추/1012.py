import sys
from collections import deque

sys.setrecursionlimit(10 ** 6) # 재귀 호출 깊이 제한 늘리기

# 상하좌우 이동을 위한 바얗ㅇ 벡터
# dy: 행 변화 (상: -1, 하: +1, 좌우: 0)
# dx: 열 변화 (상하: 0, 좌: -1, 우: 1)
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(field, visited, start_r, start_c, N, M):
    q = deque()
    q.append((start_r, start_c)) # 시작점을 큐에 추가
    visited[start_r][start_c] = True # 시작점 방문 표시

    while q:
        curr_r, curr_c = q.popleft() # 큐에서 현재 칸 꺼내기
        
        # 상하좌우 네 방향으로 이동하며 이웃 칸 확인
        for i in range(4):
            next_r, next_c = curr_r + dy[i], curr_c + dx[i]
            
            # 이웃 칸이 배추밭 범위 내에 있는지 확인
            if 0 <= next_r < N and 0 <= next_c < M:
                # 이웃 칸에 배추가 있고 아직 방문하지 않았다면
                if field[next_r][next_c] == 1 and not visited[next_r][next_c]:
                    visited[next_r][next_c] = True # 방문 표시
                    q.append((next_r, next_c)) # 큐에 추가하여 다음 탐색

def solve():
    # 가로 길이 M, 세로 길이 N, 배추 위치 개수 K 입력
    M, N, K = map(int, sys.stdin.readline().split())

    # 배추밭을 0으로 초기화
    field = [[0] * M for _ in range(N)]
    # 방문 여부를 기록할 배열을 False로 초기화
    visited = [[False] * M for _ in range(N)]
    # K개의 배추 위치를 입력받아 배추밭에 1로 표시함
    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        field[y][x] = 1
    worm_count = 0 # 필요한 지렁이의 수 (연결된 배추 그룹의 개수)

    for r in range(N):
        for c in range(M):
            # 현재 칸에 배추가 있고 아직 방문하지 않았다면, 새로운 배추 그룹이 시작되는 위치
            if field[r][c] == 1 and not visited[r][c]:
                worm_count += 1 # 지렁이 한 마리 추가
                bfs(field, visited, r, c, N, M) # BFS 탐색 후 방문 표시
    print(worm_count)

T = int(sys.stdin.readline())
for _ in range(T):
    solve()
