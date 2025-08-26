n = int(input())
heights = list(map(int, input().split()))

uphills = []
current_uphill = 0

for i in range(n - 1):
    if heights[i] < heights[i + 1]:
        current_uphill += heights[i + 1] - heights[i]
    else:
        uphills.append(current_uphill)
        current_uphill = 0
    
uphills.append(current_uphill)

print(max(uphills) if uphills else 0)