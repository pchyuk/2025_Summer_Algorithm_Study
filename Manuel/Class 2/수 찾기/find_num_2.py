import sys

N = int(sys.stdin.readline())
A_set = set(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
queries = list(map(int, sys.stdin.readline().split()))

for x in queries:
    if x in A_set:
        print(1)
    else:
        print(0)
