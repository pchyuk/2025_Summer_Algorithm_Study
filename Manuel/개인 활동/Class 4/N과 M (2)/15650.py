import sys

N, M = map(int, sys.stdin.readline().split())
current_list = []

def dfs(start_num):
    if len(current_list) == M:
        print(" ".join(map(str, current_list)))
        return
    
    for i in range(start_num, N + 1):
        current_list.append(i)
        dfs(i + 1)
        current_list.pop()
    
dfs(1)
