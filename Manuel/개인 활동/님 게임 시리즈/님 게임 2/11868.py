n = int(input())
stones = list(map(int, input().split()))

xor_sum = 0
for stone in stones:
    xor_sum ^= stone

if xor_sum != 0:
    print("koosaga")
else:
    print("cubelover")
