import sys

def solve():
    expression = sys.stdin.readline().strip() # 식을 입력받고 줄바꿈 문자를 제거함
    
    # 식을 '-' 기준으로 분리
    # Ex) 1+2-3+4-5 -> ["1+2", "3+4", "5"]
    parts = expression.split("-")

    result = 0

    # 첫 번째 부분은 더함: '+'로만 연결된 숫자들의 합
    first_sum = 0
    # Ex) "1+2" -> ["1", "2"]
    first_part = parts[0].split("+")
    for num_str in first_part:
        first_sum += int(num_str)
    result += first_sum

    # 나머지 부분은 모두 뺌: 두 번째부터 마지막까지 반복
    for i in range(1, len(parts)):
        current_sum = 0
        current_part = parts[i].split("+")
        for num_str in current_part:
            current_sum += int(num_str)
            
        result -= current_sum
    
    print(result)

solve()
