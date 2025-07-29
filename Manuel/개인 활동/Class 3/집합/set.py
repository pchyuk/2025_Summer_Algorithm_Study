import sys

def solve():
    M = int(sys.stdin.readline())
    s_mask = 0

    for _ in range(M):
        command = sys.stdin.readline().split()
        op = command[0]

        if op == "add":
            x = int(command[1])
            s_mask |= (1 << (x - 1))
        elif op == "remove":
            x = int(command[1])
            s_mask &= ~(1 << (x - 1))
        elif op == "check":
            x = int(command[1])
            if(s_mask & (1 << (x - 1))) != 0:
                print(1)
            else:
                print(0)
        elif op == "toggle":
            x = int(command[1])
            s_mask ^= (1 << (x - 1))
        elif op == "all":
            s_mask = (1 << 20) - 1
        elif op == "empty":
            s_mask = 0

solve()