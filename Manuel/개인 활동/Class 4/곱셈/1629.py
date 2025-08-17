import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

A, B, C = map(int, input().split())

def power(base, exp):
    if exp == 0:
        return 1
    temp = power(base, exp // 2) % C

    if exp % 2 == 0:
        return (temp * temp) % C
    else:
        return ((temp * temp) % C * (base % C)) % C

print(power(A, B))