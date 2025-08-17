import sys
input = sys.stdin.readline

m = int(input())
bitmask = 0
for _ in range(m):
    line = input().split()
    command = line[0]

    if command == "add":
        x = int(line[1])
        bitmask |= (1 << x)
    elif command == "remove":
        x = int(line[1])
        bitmask &= ~(1 << x)
    elif command == "check":
        x = int(line[1])
        if bitmask & (1 << x):
            sys.stdout.write("1\n")
        else:
            sys.stdout.write("0\n")
    elif command == "toggle":
        x = int(line[1])
        bitmask ^= (1 << x)
    elif command == "all":
        bitmask = (1 << 21) - 1
    elif command == "empty":
        bitmask = 0
