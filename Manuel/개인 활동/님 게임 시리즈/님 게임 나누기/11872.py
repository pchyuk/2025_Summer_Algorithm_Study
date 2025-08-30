def get_grundy(n):
    if n == 0:
        return 0
    remainder = n % 4

    if remainder == 1 or remainder == 2:
        return n
    elif remainder == 3:
        return n + 1
    else:
        return n - 1
    
def solve():
    n = int(input())
    stones = list(map(int, input().split()))
    nim_sum = 0
    
    for stone in stones:
        nim_sum ^= get_grundy(stone)

    if nim_sum != 0:
        print("koosaga")
    else:
        print("cubelover")

solve()