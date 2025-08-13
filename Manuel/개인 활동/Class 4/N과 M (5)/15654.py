import sys

N, M = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))
numbers.sort()

current_list = []
visited = [False] * N

def dfs():
    if len(current_list) == M:
        print(" ".join(map(str, current_list)))
        return
    
    for i in range(N):
        if not visited[i]:
            visited[i] = True
            current_list.append(numbers[i])
            dfs()
            current_list.pop()
            visited[i] = False
dfs()
