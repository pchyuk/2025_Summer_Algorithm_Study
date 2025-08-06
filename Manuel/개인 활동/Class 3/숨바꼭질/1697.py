import sys
from collections import deque

def solve():
    input = sys.stdin.readline

    N, K = map(int, input().split())

    MAX_POS = 100001
    visited_time = [-1] * MAX_POS

    q = deque()
    q.append((N, 0))
    visited_time[N] = 0

    while q:
        current_pos, time = q.popleft()

        if current_pos == K:
            print(time)
            return
        
        next_moves = [current_pos - 1, current_pos + 1, current_pos * 2]

        for next_pos in next_moves:
            if 0 <= next_pos < MAX_POS and visited_time[next_pos] == -1:
                visited_time[next_pos] = time + 1
                q.append((next_pos, time + 1))
solve()