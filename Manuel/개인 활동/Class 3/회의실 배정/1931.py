import sys

def solve():
    input = sys.stdin.readline

    N = int(input())
    meetings = []
    for _ in range(N):
        meetings.append(list(map(int, input().split())))
    
    # 회의들을 정렬 (람다 함수 이용)
    meetings.sort(key = lambda x: (x[1], x[0]))

    meeting_count = 0
    last_end_time = 0

    for start, end in meetings:
        if start >= last_end_time:
            meeting_count += 1
            last_end_time = end
    
    print(meeting_count)

solve()