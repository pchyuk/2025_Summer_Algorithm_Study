import sys
import time

def selection_sort(arr):
    n = len(arr)

    # 정렬되지 않은 부분 배열의 시작 인덱스
    for i in range(n - 1):
        # 가장 작은 원소의 인덱스
        min_index = i
        
        # 정렬되지 않은 부분 배열에서 최솟값 찾기
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        
        # 찾은 최솟값과 현재 위치의 원소 교환
        arr[i], arr[min_index] = arr[min_index], arr[i]

def main():
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    selection_sort(numbers)

    end_time = time.perf_counter()

    for num in numbers:
        print(num)
    
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file = sys.stderr)

main()