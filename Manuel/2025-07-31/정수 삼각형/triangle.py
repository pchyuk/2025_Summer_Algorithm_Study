import sys

def solve():
    n = int(sys.stdin.readline())
    triangle = []

    for _ in range(n):
        triangle.append(list(map(int, sys.stdin.readline().split())))
    
    for i in range(1, n):
        for j in range(i + 1):
            if j == 0:
                triangle[i][j] += triangle[i - 1][j]
            elif j == i:
                triangle[i][j] += triangle[i - 1][j - 1]
            else:
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j])
    
    print(max(triangle[n - 1]))

solve()
