import sys

def solve():
    N, M = map(int, sys.stdin.readline().split())
    
    never_heard = set()
    for _ in range(N):
        name = sys.stdin.readline().strip()
        never_heard.add(name)
    
    never_heard_seen = []
    for _ in range(M):
        name = sys.stdin.readline().strip()
        if name in never_heard:
            never_heard_seen.append(name)
    
    never_heard_seen.sort()

    print(len(never_heard_seen))
    for name in never_heard_seen:
        print(name)

solve()