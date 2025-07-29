import sys

N = int(sys.stdin.readline())
points = []

for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())
    points.append((x, y))

points.sort(key = lambda p: (p[0], p[1]))

for x, y in points:
    print(x, y)