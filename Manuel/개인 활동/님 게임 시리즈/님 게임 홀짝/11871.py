n = int(input())
stones = list(map(int, input().split()))

nim_sum = 0

for stone in stones:
    if stone % 2 == 0:
        nim_sum ^= stone // 2 - 1
    else:
        nim_sum ^= stone // 2 + 1

if nim_sum != 0:
    print("koosaga")
else:
    print("cubelover")