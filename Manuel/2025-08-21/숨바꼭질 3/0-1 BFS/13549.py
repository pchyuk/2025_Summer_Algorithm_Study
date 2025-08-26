import sys
from collections import deque
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    if n >= k:
        print(n - k)
        return
    
    MAX = 100001
    time = [-1] * MAX
    dq = deque()
    dq.append(n)
    time[n] = 0

    while dq:
        current = dq.popleft()

        teleport = current * 2
        if 0 <= teleport < MAX and time[teleport] == -1:
            time[teleport] = time[current]
            dq.appendleft(teleport)
        
        walk_back = current - 1
        if 0 <= walk_back < MAX and time[walk_back] == -1:
            time[walk_back] = time[current] + 1
            dq.append(walk_back)
        
        walk_forward = current + 1
        if 0 <= walk_forward < MAX and time[walk_forward] == -1:
            time[walk_forward] = time[current] + 1
            dq.append(walk_forward)
    
    print(time[k])

solve()