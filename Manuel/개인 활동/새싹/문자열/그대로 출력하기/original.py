import sys

while True:
    try:
        line = sys.stdin.readline()
        if not line:
            break
        print(line, end = '')
    except EOFError:
        break
