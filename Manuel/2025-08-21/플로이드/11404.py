import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

INF = float('inf')
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    distance[a][b] = min(distance[a][b], c)

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if distance[i][k] != INF and distance[k][j] != INF:
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if distance[i][j] == INF:
            sys.stdout.write("0 ")
        else:
            sys.stdout.write(f"{distance[i][j]} ")
    sys.stdout.write("\n")
