import sys

count = 0

def solve(n, r, c):
    global count
    if n == 0:
        return
    
    half = 2 ** (n - 1)
    area = half * half

    if r < half and c < half:
        solve(n - 1, r, c)
    elif r < half and c >= half:
        count += area
        solve(n - 1, r, c - half)
    elif r >= half and c < half:
        count += 2 * area
        solve(n - 1, r - half, c)
    else:
        count += 3 * area
        solve(n - 1, r - half, c - half)

def main():
    sys.setrecursionlimit(10 ** 6)

    N, r, c = map(int, sys.stdin.readline().split())
    solve(N, r, c)
    print(count)

main()