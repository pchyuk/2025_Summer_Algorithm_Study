import sys
from collections import deque

def solve():
    N, K = map(int, sys.stdin.readline().split())
    people = deque(range(1, N + 1))
    josephus_sequence = []

    while people:
        for _ in range(K - 1):
            people.append(people.popleft())
        josephus_sequence.append(people.popleft())
    
    print("<" + ", ".join(map(str, josephus_sequence)) + ">")

solve()