import sys

count_prints = [0, 0] # count_prints[0]은 0이 출력되는 횟수, count_prints[1]은 1의 횟수

def fibonacci_recursive(n):
    global count_prints # count_prints를 여러 함수 내에서 수정하므로 전역 변수로 선언

    if n == 0:
        count_prints[0] += 1 # 0이 출력되는 횟수 증가
        return 0
    elif n == 1:
        count_prints[1] += 1 # 1이 출력되는 횟수 증가
        return 1
    else:
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

def solve():
    global count_prints # solve 함수 내에서도 사용

    T = int(sys.stdin.readline()) # 테스트 케이스 개수 T 입력

    for _ in range(T):
        N = int(sys.stdin.readline())
        count_prints = [0, 0] # count_prints 값 초기화
        
        # 함수의 반환 값은 무시. 함수를 재귀적으로 출력하여 0과 1의 출력 횟수 계산
        fibonacci_recursive(N)

        print(count_prints[0], count_prints[1])

solve()
