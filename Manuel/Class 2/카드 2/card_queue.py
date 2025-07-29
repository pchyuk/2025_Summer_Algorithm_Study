import sys
from collections import deque

def solve():
    N = int(sys.stdin.readline())
    cards = deque(range(1, N + 1))

    while len(cards) > 1:
        cards.popleft()
        if len(cards) > 0:
            top_card = cards.popleft()
            cards.append(top_card)
    print(cards[0])

solve()