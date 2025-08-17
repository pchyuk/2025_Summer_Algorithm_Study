import sys
input = sys.stdin.readline

m = int(input())
s = [False] * 21

for _ in range(m):
    line = input().split()
    command = line[0]

    if command == "add":
        x = int(line[1])
        s[x] = True
    elif command == "remove":
        x = int(line[1])
        s[x] = False
    elif command == "check":
        x = int(line[1])
        if s[x]:
            sys.stdout.write("1\n")
        else:
            sys.stdout.write("0\n")
    elif command == "toggle":
        x = int(line[1])
        s[x] = not s[x]
    elif command == "all":
        s = [False] + [True] * 20
    elif command == "empty":
        s = [False] * 21
