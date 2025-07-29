import sys

n, x = map(int, sys.stdin.readline().strip().split())
a = list(map(int, sys.stdin.readline().strip().split()))
result = []

for num in a:
    if num < x:
        result.append(num)

print(*result)