import sys
from collections import deque

def solve():
    # 문서의 개수 N과 궁금한 문서의 위치 M 입력
    N, M = map(int, sys.stdin.readline().split())

    # N개 문서의 중요도를 리스트로 입력
    priorities = list(map(int, sys.stdin.readline().split()))

    # 큐에 (중요도, 원래 인덱스) 쌍을 저장
    q = deque()
    for i in range(N):
        q.append((priorities[i], i))
    print_order_count = 0 # 인쇄 순서를 세는 변수

    # 큐가 빌 때까지
    while q:
        current_doc = q.popleft()
        current_priority = current_doc[0]
        current_original_index = current_doc[1]

        # 큐에 더 높은 중요도의 문서가 있는지 확인함
        higher_yes = False
        for p, _ in q:
            if p > current_priority:
                higher_yes = True
                break
        if higher_yes: # 더 높은 중요도의 문서가 있으면 큐의 맨 뒤로
            q.append(current_doc)
        else:
            # 없으면 인쇄
            print_order_count += 1
            if current_original_index == M:
                print(print_order_count)
                return
T = int(sys.stdin.readline())
for _ in range(T):
    solve()