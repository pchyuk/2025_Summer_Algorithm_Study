import sys
import heapq

def solve():
    input = sys.stdin.readline

    N = int(input())
    min_heap = []

    for _ in range(N):
        x = int(input())

        if x == 0:
            if not min_heap:
                print(0)
            else:
                print(heapq.heappop(min_heap))
        else:
            heapq.heappush(min_heap, x)

solve()