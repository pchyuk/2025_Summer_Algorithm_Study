n = int(input())
stones = list(map(int, input().split()))

nim_sum = 0
for stone in stones:
    nim_sum ^= stone

if nim_sum == 0:
    print(0)
else:
    count = 0

    for i in range(n):
        target = nim_sum ^ stones[i]
        remove = stones[i] - target
        if 1 <= remove <= stones[i]:
            count += 1
    
    print(count)