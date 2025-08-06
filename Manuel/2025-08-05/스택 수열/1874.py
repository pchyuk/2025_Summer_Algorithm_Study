import sys

def main():
    input = sys.stdin.readline

    n = int(input())

    s = [] # 스택 - 리스트로 구현함
    result = [] # 연산 결과 스택
    current_num = 1 # 스택에 push될 다음 숫자

    for _ in range(n):
        target_num = int(input())

        # Case 1: 스택에 push될 다음 숫자가 target_num보다 작거나 같은 경우
        # target_num까지 push 연산을 수행
        while current_num <= target_num:
            s.append(current_num)
            result.append('+')
            current_num += 1

        # Case 2: 스택의 top이 target_num과 같은 경우
        # pop 수행
        if s and s[-1] == target_num:
            s.pop()
            result.append('-')

        # Case 3: 스택의 top이 target_num과 다른 경우
        else:
            print("NO")
            return
    
    for op in result:
        print(op)

main()