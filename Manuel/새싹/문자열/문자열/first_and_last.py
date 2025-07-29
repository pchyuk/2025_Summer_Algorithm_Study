import sys

T = int(sys.stdin.readline().strip())

for _ in range(T):
    S = sys.stdin.readline().strip()
    first_char = S[0]
    last_char = S[-1]
    print(first_char + last_char)
