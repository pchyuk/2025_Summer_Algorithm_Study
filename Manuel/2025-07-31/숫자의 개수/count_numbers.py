import sys

def solve():
    A = int(sys.stdin.readline())
    B = int(sys.stdin.readline())
    C = int(sys.stdin.readline())
    product = A * B * C
    str_product = str(product)

    counts = [0] * 10
    for char_digit in str_product:
        int_digit = int(char_digit)
        counts[int_digit] += 1
    
    for i in range(10):
        print(counts[i])

solve()