import sys

# DFS 탐색 함수:
# graph: 인접 리스트로 표현된 그래프
# visited: 방문 여부가 기록된 리스트
# current_com: 현재 탐색하는 컴퓨터 번호
# infected_count: 감염된 컴퓨터 수를 저장하는 리스트

def dfs(graph, visited, current_com, infected_count):
    visited[current_com] = True # 현재 컴퓨터를 방문했다고 표기
    infected_count[0] += 1 # 감염된 컴퓨터 수 1 증가시킴

    for neighbour in graph[current_com]: # 현재 컴퓨터에 연결된 모든 인접 컴퓨터 확인
        if not visited[neighbour]: # 만일 이웃 컴퓨터를 방문하지 않았다면
            dfs(graph, visited, neighbour, infected_count) # 이웃 컴퓨터에 대하여 DFS를 재귀적으로 호출 (인접한 컴퓨터로 이동하며 같은 연산 수행)

def solve():
    num_computers = int(sys.stdin.readline()) # 컴퓨터의 수
    num_connections = int(sys.stdin.readline()) # 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수
    graph = [[] for _ in range(num_computers + 1)] # 인접 리스트로 표현된 그래프. 컴퓨터 번호가 1부터 시작하므로 num_computers + 1 크기로 리스트를 만듦.

    for _ in range(num_connections): # 연결 정보 추가
        c1, c2 = map(int, sys.stdin.readline().split())
        # 양방향 연결이므로 양쪽에 데이터 추가
        graph[c1].append(c2)
        graph[c2].append(c1)
    
    visited = [False] * (num_computers + 1) # 방문 여부 기록용 배열. 초기값은 모두 False로 지정.
    infected_count = [0] # 감염된 컴퓨터 수

    # 1번 컴퓨터부터 DFS 탐색 시작
    dfs(graph, visited, 1, infected_count)

    # 최종적으로 감염된 컴퓨터의 수에서 1번 자신을 제외하고 출력 (1번은 무조건 감염되므로)
    print(infected_count[0] - 1)

solve()