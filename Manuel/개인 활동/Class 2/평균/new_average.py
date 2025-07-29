import sys

N = int(sys.stdin.readline())

scores = list(map(int, sys.stdin.readline().split()))

M = max(scores)

new_sum = 0.0

for score in scores:
    new_score = (score / M) * 100
    new_sum += new_score

new_average = new_sum / N

print(new_average)