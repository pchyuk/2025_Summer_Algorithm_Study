n = int(input())
heights = list(map(int, input().split()))

max_uphill = 0
current_uphill = 0

for i in range(n - 1):
    if heights[i] < heights[i + 1]:
        current_uphill += heights[i + 1] - heights[i]
        max_uphill = max(max_uphill, current_uphill)
    else:
        current_uphill = 0

print(max_uphill)