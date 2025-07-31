import sys
from collections import deque

def solve():
    # 명령의 수
    N = int(sys.stdin.readline())
    # 큐로 사용할 deque 촉화
    queue = deque()

    # N개의 명령 처리
    for _ in range(N):
        op = sys.stdin.readline().split() # 명령을 공백으로 분리하여 읽기
        
        # 명령의 종류에 따라 다르게 처리
        if op[0] == 'push':
            X = int(op[1])
            queue.append(X)
        elif op[0] == 'pop':
            if queue: # 큐가 비어있지 않으면
                print(queue.popleft()) # 큐의 앞 요소를 제거하고 출력
            else: # 비어 있다면
                print(-1)
        elif op[0] == 'size':
            print(len(queue)) # 큐의 길이 (큐에 들어있는 정수의 개수) 출력
        elif op[0] == 'empty':
            if not queue: # 큐가 비어 있으면
                print(1)
            else:
                print(0)
        elif op[0] == 'front':
            if queue: # 큐가 비어 있지 않으면
                print(queue[0]) # 큐의 맨 앞 요소 확인
            else:
                print(-1)
        elif op[0] == 'back':
            if queue: # 큐가 비어 있지 않으면
                print(queue[-1]) # 큐의 맨 뒤 요소 확인
            else:
                print(-1)

solve()
