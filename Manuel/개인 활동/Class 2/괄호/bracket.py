import sys

def is_vps(ps_string):
    stack = []
    for char in ps_string:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack:
                return "NO"
            stack.pop()
    if not stack:
        return "YES"
    else:
        return "NO"

T = int(sys.stdin.readline())

for _ in range(T):
    ps_string = sys.stdin.readline().strip()
    print(is_vps(ps_string))
