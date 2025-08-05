import sys
import time

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def main():
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    insertion_sort(numbers)

    end_time = time.perf_counter()

    for num in numbers:
        print(num)
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file = sys.stderr)

main()