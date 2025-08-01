import sys

recursion_count = 0 # 재귀 함수의 호출 횟수 카운터

def recursion(s, l, r): # l은 왼쪽 끝, r은 오른쪽 끝
    global recursion_count # 함수 내에서 변수를 수정하기 위함
    recursion_count += 1 # 일단 호출되었으므로 1 증가 (그 다음부터는 호출할 때마다 증가)

    if l >= r: # 왼쪽 포인터가 오른쪽보다 크거나 같아지면 문자열의 모든 문자를 비교했다는 뜻
        return 1 # 펠린드롬이라는 의미
    elif s[l] != s[r]: # 양 끝의 문자가 다르면 팰린드롬이 아님
        return 0
    else:
        return recursion(s, l + 1, r - 1) # 왼쪽은 한 칸 뒤로, 오른쪽은 한 칸 앞으로 이동하여 비교

def isPalindrome(s):
    global recursion_count
    recursion_count = 0 # 이 함수를 호출할 때마다 카운터를 초기화함
    return recursion(s, 0, len(s) - 1) # l 포인터를 맨 왼쪽에 두고 r 포인터는 마지막에서 한 칸 앞으로 이동

def solve():
    T = int(sys.stdin.readline()) # 테스트 케이스 개수
    for _ in range(T):
        S = sys.stdin.readline().strip() # 문자열 S 입력받음
        is_palindrome_result = isPalindrome(S) # isPalindrome 함수의 반환 값
        global recursion_count
        print(is_palindrome_result, recursion_count)

solve()