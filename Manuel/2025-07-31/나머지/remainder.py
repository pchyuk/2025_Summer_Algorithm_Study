import sys

def solve():
    # set은 중복되는 값을 자동으로 제거함
    remainders = set()

    for _ in range(10): # 10번 동안
        num = int(sys.stdin.readline()) # 정수 입력받기
        remainder = num % 42 # 입력받은 정수를 42로 나눈 나머지 구하기
        remainders.add(remainder) # set에 값 추가하기
    
    print(len(remainders)) # 중복 제거된 set의 값 개수 출력

solve()