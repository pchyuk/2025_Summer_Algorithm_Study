import sys
import time

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    # 피봇을 배열의 첫 번쨰 원소로 선택
    pivot = arr[0]
    tail = arr[1:]

    # 피봇보다 작은 원소들의 배열
    left_side = [x for x in tail if x <= pivot]
    # 피봇보다 큰 원소들의 배열
    right_side = [x for x in tail if x > pivot]
    
    # 재귀를 사용하여 정렬
    return quick_sort(left_side) + [pivot] + quick_sort(right_side)

def main():
    sys.setrecursionlimit(10 ** 6)
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    sorted_numbers = quick_sort(numbers)

    end_time = time.perf_counter()

    for num in sorted_numbers:
        print(num)

    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file = sys.stderr)

main()