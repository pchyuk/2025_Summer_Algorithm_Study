import sys

sys.setrecursionlimit(10 ** 6)

board = []

def draw_star(x, y, n):
    if n == 3:
        for i in range(3):
            for j in range(3):
                if i == 1 and j == 1:
                    board[x + i][y + j] = ' '
                else:
                    board[x + i][y + j] = '*'
        return
    
    new_n = n // 3

    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1:
                for row in range(x + i * new_n, x + (i * 1) * new_n):
                    for col in range(y + j * new_n):
                        board[row][col] = ' '
            else:
                draw_star(x + i * new_n, y + j * new_n, new_n)

def main():
    input = sys.stdin.readline

    N = int(input())
    global board
    board = [[' ' for _ in range(N)] for _ in range(N)]

    draw_star(0, 0, N)

    for i in range(N):
        sys.stdout.write("".join(board[i]) + "\n")

main()