import sys
import time

def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # 각 자릿수에 해당하는 숫자 세기
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    
    # count 배열을 누적 합으로 변경
    for i in range(1, 10):
        count[i] += count[i - 1]

    # 뒤에서부터 순회하며 output 배열에 저장
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1
    
    # output 배열의 내용을 원래 배열로 복사
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    # 가장 큰 값을 찾아 자릿수 결정
    if not arr:
        return
    max_val = max(arr)

    # 1의 자리부터 시작하여 자릿수별로 계수 정렬 수행
    exp = 1
    while max_val // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

def main():
    input = sys.stdin.readline

    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    radix_sort(numbers)

    end_time = time.perf_counter()

    for num in numbers:
        print(num)
    
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.6f}ms\n", file = sys.stderr)

main()