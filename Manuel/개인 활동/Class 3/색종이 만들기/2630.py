import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

counts = [0, 0]
board = []

def check_colour(row, col, size):
    standard_colour = board[row][col]
    for i in range(row, row + size):
        for j in range(col, col + size):
            if board[i][j] != standard_colour:
                return False
    return True

def solve(row, col, size):
    if check_colour(row, col, size):
        colour = board[row][col]
        counts[colour] += 1
        return
    
    new_size = size // 2
    solve(row, col, new_size)
    solve(row, col + new_size, new_size)
    solve(row + new_size, col, new_size)
    solve(row + new_size, col + new_size, new_size)

def main():
    N = int(input())

    for _ in range(N):
        board.append(list(map(int, input().split())))
    solve(0, 0, N)

    print(counts[0])
    print(counts[1])

main()