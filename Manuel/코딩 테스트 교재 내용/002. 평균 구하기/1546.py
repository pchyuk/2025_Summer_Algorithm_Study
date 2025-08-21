N = int(input())
scores = list(map(int, input().split()))

my_max = max(scores)
scores_sum = sum(scores)

print(scores_sum * 100 / my_max / N)