import sys
import time

def heapify(arr, n, i):
    largest = i # Root
    left = 2 * i + 1
    right = 2 * i + 2

    # 왼쪽 자식이 현재 루트보다 크면
    if left < n and arr[left] > arr[largest]:
        largest = left
    # 오른쪽 자식이 현재 가장 큰 값보다 크면
    if right < n and arr[right] > arr[largest]:
        largest = right
    # 가장 큰 값이 루트가 아니면 교환, 재귀적으로 heapify 호출
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # 최대 힙으로 변환
    # 마지막 부모 노드부터 루트까지 순회
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    # 정렬
    for i in range(n - 1, 0, -1):
        # 루트(최대값)와 마지막 원소 교환
        arr[i], arr[0] = arr[0], arr[i]
        # 힙 크기 줄이기, heapify 호출
        heapify(arr, i, 0)

def main():
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    heap_sort(numbers)

    end_time = time.perf_counter()

    for num in numbers:
        print(num)
    
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file = sys.stderr)

main()