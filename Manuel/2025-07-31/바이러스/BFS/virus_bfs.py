import sys
from collections import deque # 큐 구현을 위해 deque 사용

def solve():
    num_computers = int(sys.stdin.readline()) # 첫째 줄: 컴퓨터 수
    num_connections = int(sys.stdin.readline()) # 둘째 줄: 연결되어 있는 컴퓨터 쌍의 수
    graph = [[] for _ in range(num_computers + 1)] # 그래프를 인접 리스트로 표현; 컴퓨터의 번호를 1부터 N까지 매김

    for _ in range(num_connections): # 연결 정보를 그래프에 추가
        c1, c2 = map(int, sys.stdin.readline().split())
        # 양방향 연결
        graph[c1].append(c2)
        graph[c2].append(c1)
    
    # 방문 여부를 기록할 배열 (처음에는 모두 False로 초기화)
    visited = [False] * (num_computers + 1) # 컴퓨터의 번호가 1부터 시작하므로 배열은 (num_computers + 1) 크기로 만듦

    # BFS용 큐 생성
    q = deque()
    # 시작점인 1번 컴퓨터 넣기
    q.append(1)
    # 1번 컴퓨터는 방문 표시
    visited[1] = True

    infected_count = 0 # 1번을 제외한 바이러스에 걸리는 컴퓨터의 수

    while q: # BFS 탐색 시작
        current_computer = q.popleft() # 큐에서 현재 컴퓨터를 꺼냄

        # 현재 컴퓨터에 연결된 모든 이웃 컴퓨터 확인
        for neighbour in graph[current_computer]:
            if not visited[neighbour]: # 이웃 컴퓨터를 방문하지 않았다면
                visited[neighbour] = True # 방문했다고 표시
                q.append(neighbour) # 큐에 삽입
                infected_count += 1 # 감염된 컴퓨터 수 1 증가
        
    print(infected_count) # 감염된 컴퓨터 수 출력

solve()