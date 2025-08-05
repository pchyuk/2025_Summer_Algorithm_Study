import sys
import time

def bubble_sort(arr):
    n = len(arr)

    # 배열의 끝에서부터 정렬된 원소가 쌓여가기 때문에 정렬 범위는 n-1부터 1까지 줄어듦
    for i in range(n - 1):
        swapped = False
        # 인접 원소 비교 후 교환
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    
def main():
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    bubble_sort(numbers)

    end_time = time.perf_counter()

    for num in numbers:
        print(num)
    
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file = sys.stderr)

main()