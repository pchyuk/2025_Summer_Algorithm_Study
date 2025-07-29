import sys

def solve():
    N = int(sys.stdin.readline())
    times = list(map(int, sys.stdin.readline().split()))
    times.sort()

    total_waiting_time = 0
    current_time = 0

    for time_needed in times:
        current_time += time_needed
        total_waiting_time += current_time
    
    print(total_waiting_time)

solve()