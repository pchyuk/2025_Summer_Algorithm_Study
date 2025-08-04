import sys
import time

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_sorted = merge_sort(left_half)
    right_sorted = merge_sort(right_half)

    return merge(left_sorted, right_sorted)

def merge(left, right):
    merged_list = []
    i, j = 0, 0

    # 양쪽 리스트를 비교하며 더 작은 값을 merged_list에 추가
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged_list.append(left[i])
            i += 1
        else:
            merged_list.append(right[j])
            j += 1
    
    # 남은 요소들을 추가
    merged_list.extend(left[i:])
    merged_list.extend(right[j:])

    return merged_list

def main():
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]
    
    start_time = time.perf_counter()

    sorted_numbers = merge_sort(numbers)

    end_time = time.perf_counter()

    for num in sorted_numbers:
        print(num)
    
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file=sys.stderr)

main()