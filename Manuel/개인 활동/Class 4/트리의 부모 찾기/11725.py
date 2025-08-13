import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n = int(input())
adj = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

parent = [0] * (n + 1)
q = deque([1])
parent[1] = 1

while q:
    current_node = q.popleft()
    for neighbour in adj[current_node]:
        if parent[neighbour] == 0:
            parent[neighbour] = current_node
            q.append(neighbour)

for i in range(2, n + 1):
    print(parent[i])
