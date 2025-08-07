import sys

def main():
    input = sys.stdin.readline

    T = int(input())
    for _ in range(T):
        result = input().strip()
        total_score = 0
        streak = 0

        for char in result:
            if char == 'O' or char == 'o':
                streak += 1
                total_score += streak
            else:
                streak = 0
        print(total_score)

main()