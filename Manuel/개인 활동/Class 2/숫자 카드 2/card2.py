import sys

N = int(sys.stdin.readline())
card_counts = {}
cards_N = list(map(int, sys.stdin.readline().split()))

for card_num in cards_N:
    card_counts[card_num] = card_counts.get(card_num, 0) + 1

M = int(sys.stdin.readline())
queries = list(map(int, sys.stdin.readline().split()))

results = []

for query_num in queries:
    count = card_counts.get(query_num, 0)
    results.append(count)

print(*results)