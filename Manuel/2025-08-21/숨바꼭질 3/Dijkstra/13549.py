import sys
import heapq
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    if n >= k:
        print(n - k)
        return
    
    MAX = 100001
    time = [float('inf')] * MAX
    pq = []

    time[n] = 0
    heapq.heappush(pq, (0, n))

    while pq:
        current_time, current_pos = heapq.heappop(pq)

        if current_time > time[current_pos]:
            continue
        if current_pos == k:
            print(current_time)
            return
        
        teleport = current_pos * 2
        if 0 <= teleport < MAX and time[teleport] > current_time:
            time[teleport] = current_time
            heapq.heappush(pq, (current_time, teleport))
        
        walk_back = current_pos - 1
        if 0 <= walk_back < MAX and time[walk_back] > current_time + 1:
            time[walk_back] = current_time + 1
            heapq.heappush(pq, (current_time + 1, walk_back))
        
        walk_forward = current_pos + 1
        if 0 <= walk_forward < MAX and time[walk_forward] > current_time + 1:
            time[walk_forward] = current_time + 1
            heapq.heappush(pq, (current_time + 1, walk_forward))

solve()