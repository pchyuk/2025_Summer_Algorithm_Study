#include <iostream>  // 입출력을 위해 필요한 헤더 파일
#include <vector>    // std::vector를 사용하기 위한 헤더 파일
#include <string>    // std::string을 사용하기 위한 헤더 파일
#include <algorithm> // std::min을 사용하기 위한 헤더 파일
#include <limits>    // std::numeric_limits를 사용하기 위함 (선택사항, min_repaints 초기화 시)

int main() {
    // 빠른 입출력 설정을 위한 코드입니다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M; // N(행의 수)과 M(열의 수)
    std::cin >> N >> M;

    // 보드의 상태를 vector<string>으로 저장합니다.
    std::vector<std::string> board(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> board[i];
    }

    // 다시 칠해야 하는 정사각형 개수의 최솟값을 저장할 변수
    // 8x8 보드의 모든 칸을 다시 칠하는 것이 최대이므로 64로 초기화합니다.
    // 또는 int의 최댓값으로 초기화 (std::numeric_limits<int>::max())
    int min_repaints = 64; 

    // 큰 보드 내에서 8x8 부분 보드의 시작 행(start_row)을 순회합니다.
    // start_row는 0부터 N-8까지 가능합니다.
    for (int start_row = 0; start_row <= N - 8; ++start_row) {
        // 8x8 부분 보드의 시작 열(start_col)을 순회합니다.
        // start_col은 0부터 M-8까지 가능합니다.
        for (int start_col = 0; start_col <= M - 8; ++start_col) {
            
            int count_w_start = 0; // 'W'로 시작하는 체스판으로 만들 때 필요한 재칠 개수
            
            // 8x8 부분 보드 내의 각 칸을 순회합니다.
            for (int r = start_row; r < start_row + 8; ++r) {
                for (int c = start_col; c < start_col + 8; ++c) {
                    // 현재 칸 (r, c)의 예상 색깔을 'W'로 시작하는 체스판 기준으로 결정
                    // (r + c)의 합이 짝수이면 'W', 홀수이면 'B'여야 합니다.
                    if ((r + c) % 2 == 0) { // 합이 짝수일 때 (이상적인 'W' 위치)
                        if (board[r][c] != 'W') { // 실제 색이 'W'가 아니면
                            count_w_start++;     // 다시 칠해야 함
                        }
                    } else { // 합이 홀수일 때 (이상적인 'B' 위치)
                        if (board[r][c] != 'B') { // 실제 색이 'B'가 아니면
                            count_w_start++;     // 다시 칠해야 함
                        }
                    }
                }
            }
            
            // 'B'로 시작하는 체스판으로 만들 때 필요한 재칠 개수
            // 총 64칸에서 'W' 시작 패턴 재칠 개수를 뺀 것과 같습니다.
            int count_b_start = 64 - count_w_start;
            
            // 현재 부분 보드에서 'W' 시작과 'B' 시작 중 더 적은 재칠 개수를 선택
            int current_min_in_sub_board = std::min(count_w_start, count_b_start);
            
            // 전체 최소 재칠 개수를 업데이트합니다.
            min_repaints = std::min(min_repaints, current_min_in_sub_board);
        }
    }

    // 최종적으로 계산된 최소 재칠 개수를 출력합니다.
    std::cout << min_repaints << '\n';

    return 0; // 프로그램이 성공적으로 종료되었음을 나타냅니다.
}