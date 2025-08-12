import sys
input = sys.stdin.readline

s = input().strip()
result = [-1] * 26

for i, char in enumerate(s):
    index = ord(char) - ord('a')

    if result[index] == -1:
        result[index] = i

print(' '.join(map(str, result)))