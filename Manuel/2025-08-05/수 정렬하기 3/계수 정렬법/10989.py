import sys
import time

def main():
    input = sys.stdin.readline

    start_time = time.perf_counter()

    N = int(input()) # 수의 개수 입력
    
    # 입력 값을 모두 읽어서 저장
    input_numbers = [int(input()) for _ in range(N)]

    start_time = time.perf_counter()

    count_array = [0] * 10001

    for num in input_numbers:
        # 해당 숫자의 등장 횟수를 증가시킴
        count_array[num] += 1
    
    # count_array를 순회하며 정렬된 결과 출력
    for i in range(1, 10001):
        # 해당 숫자가 존재한다면:
        if count_array[i] > 0:
            # 등장 횟수만큼 숫자 출력
            for _ in range(count_array[i]):
                print(i)
    
    end_time = time.perf_counter()
    
    print(f"\n실행 시간: {(end_time - start_time) * 1000:.2f}ms\n", file=sys.stderr)

main()