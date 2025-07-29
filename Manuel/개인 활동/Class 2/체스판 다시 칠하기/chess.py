import sys

def solve():
    # 첫째 줄에 N(행의 수)과 M(열의 수)을 입력받습니다.
    # N과 M은 8 이상 50 이하의 자연수입니다.
    N, M = map(int, sys.stdin.readline().split())

    # 보드의 상태를 리스트 안에 문자열로 저장합니다.
    # board[r][c] 형식으로 접근할 수 있습니다.
    board = []
    for _ in range(N):
        board.append(sys.stdin.readline().strip()) # 각 행의 문자열을 입력받아 줄바꿈 문자 제거

    # 다시 칠해야 하는 정사각형 개수의 최솟값을 저장할 변수입니다.
    # 8x8 = 64이므로, 최대 64칸을 칠해야 할 수 있습니다. 64로 초기화합니다.
    min_repaints = 64

    # 큰 보드 내에서 8x8 부분 보드의 시작 행(start_row)을 순회합니다.
    # N-8까지 반복합니다. (파이썬 range는 끝 인덱스 미만까지 반복)
    for start_row in range(N - 7): # N-8을 포함하려면 N-7까지 range
        # 8x8 부분 보드의 시작 열(start_col)을 순회합니다.
        # M-8까지 반복합니다.
        for start_col in range(M - 7): # M-8을 포함하려면 M-7까지 range
            
            # 현재 8x8 부분 보드를 왼쪽 위가 'W'로 시작하는 체스판으로 만들 때 필요한 재칠 개수
            count_w_start = 0
            
            # 8x8 부분 보드 내의 각 칸을 순회합니다.
            # r은 현재 행 인덱스, c는 현재 열 인덱스입니다.
            for r in range(start_row, start_row + 8):
                for c in range(start_col, start_col + 8):
                    
                    # 현재 칸 (r, c)의 예상 색깔을 'W'로 시작하는 체스판 기준으로 결정
                    # (r + c)의 합이 짝수이면 'W'가 와야 할 위치, 홀수이면 'B'가 와야 할 위치
                    if (r + c) % 2 == 0: # 합이 짝수일 때 (이상적인 'W' 위치)
                        if board[r][c] != 'W': # 실제 칸의 색깔이 'W'가 아니면
                            count_w_start += 1 # 다시 칠해야 함
                    else: # 합이 홀수일 때 (이상적인 'B' 위치)
                        if board[r][c] != 'B': # 실제 칸의 색깔이 'B'가 아니면
                            count_w_start += 1 # 다시 칠해야 함
            
            # 'B'로 시작하는 체스판으로 만들 때 필요한 재칠 개수는
            # 총 64칸에서 'W'로 시작할 때의 재칠 개수를 뺀 것과 같습니다.
            count_b_start = 64 - count_w_start
            
            # 현재 8x8 부분 보드에서 'W' 시작과 'B' 시작 중 더 적은 재칠 개수를 선택
            current_min_repaints_in_sub_board = min(count_w_start, count_b_start)
            
            # 전체 최소 재칠 개수를 업데이트합니다.
            min_repaints = min(min_repaints, current_min_repaints_in_sub_board)
            
    # 최종적으로 계산된 최소 재칠 개수를 출력합니다.
    print(min_repaints)

solve() # 함수 호출로 프로그램 실행