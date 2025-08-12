checkList = [0] * 4 # A, C, G, T의 최소 개수를 저장하는 리스트
myList = [0] * 4 # 현재 비밀번호에 포함된 문자의 개수를 저장하는 리스트
checkSecret = 0 # 조건 중 몇 개가 충족됐는지 세는 변수

# 문자가 추가될 때 호출되는 함수
def myadd(c):
    global checkList, myList, checkSecret
    if c == 'A': # A가 추가될 경우
        myList[0] += 1
        if myList[0] == checkList[0]: # A의 개수가 요구 개수와 같아지면
            checkSecret += 1 # 조건 충족
    elif c == 'C':
        myList[1] += 1
        if myList[1] == checkList[1]:
            checkSecret += 1
    elif c == 'G':
        myList[2] += 1
        if myList[2] == checkList[2]:
            checkSecret += 1
    elif c == 'T':
        myList[3] += 1
        if myList[3] == checkList[3]:
            checkSecret += 1

# 문자가 제거되면 호출되는 함수
def myremove(c):
    global checkList, myList, checkSecret
    if c == 'A': # A가 추가될 경우
        if myList[0] == checkList[0]: # A의 개수가 요구 개수와 같았다면
            checkSecret -= 1 # 조건 미충족 상태로 변경
        myList[0] -= 1
    elif c == 'C':
        if myList[1] == checkList[1]:
            checkSecret -= 1
        myList[1] -= 1
    elif c == 'G':
        if myList[2] == checkList[2]:
            checkSecret -= 1
        myList[2] -= 1
    elif c == 'T':
        if myList[3] == checkList[3]:
            checkSecret -= 1
        myList[3] -= 1

# S: DNA 문자열 길이, P: 비밀번호 길이
S, P = map(int, input().split())
result = 0
# DNA 문자열을 리스트로 저장하여 A에 저장
A = list(input())
# 각 문자열의 조건을 만족하는 최소 개수를 입력받아 저장
checkList = list(map(int, input().split()))

# 최소 개수가 0인 경우는 이미 조건을 만족한 것으로 간주
for i in range(4):
    if checkList[i] == 0:
        checkSecret += 1

# 첫 P개의 문자를 설정하고 조건을 검사
# 첫 P개의 문자열을 추가
for i in range(P):
    myadd(A[i])
# 첫 문자열이 모든 조건을 만족하는지 확인
if checkSecret == 4:
    result += 1
# 슬라이딩 윈도우를 한 칸씩 이동하며 조건 검사
for i in range(P, S):
    j = i - P # 윈도우에서 제거될 문자의 인덱스
    myadd(A[i]) # 새로운 문자를 문자열에 추가
    myremove(A[j]) # 가장 앞 문자를 문자열에서 제거
    # 윈도우 이동 후 모든 조건을 만족하는지 확인
    if checkSecret == 4:
        result += 1

print(result)