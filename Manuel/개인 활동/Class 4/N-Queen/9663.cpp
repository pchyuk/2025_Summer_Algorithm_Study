/*
기본 아이디어:
백트래킹 알고리즘 사용.
- 재귀 함수: 현재 행에 퀸을 놓을 위치를 찾음
- 기저 조건: 모든 행에 퀸을 성공적으로 놓으면 경우의 수를 1 증가시키고 종료
- 재귀 단계:
    - 현재 행의 각 열에 퀸을 놓아보기
    - 퀸을 놓을 수 있는 조건:
        - 같은 열에 다른 퀸이 없는가?
        - 같은 우상향 대각선에 다른 퀸이 없는가?
        - 같은 좌상향 대각선에 다른 퀸이 없는가?
        이 조건을 모두 만족하면 해당 위치에 퀸을 놓고, 다음 행에서 해당 함수를 재귀 호출
    - 재귀 호출이 끝난 후 백트래킹을 위해 퀸을 놓기 전 상태로 되돌리기
*/

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N;
int answers = 0;
// 각 열에 퀸이 있는지
vector<bool> is_col_used;
// 각 우상향 대각선에 퀸이 있는지
vector<bool> is_right_used;
// 각 좌상향 대각선에 퀸이 있는지
vector<bool> is_left_used;

// 백트래킹 함수
void solve(int row)
{
    // 기저 조건: 모든 행에 퀸을 놓았을 경우
    if(row == N)
    {
        answers++;
        return;
    }

    // 현재 행의 각 열에 퀸을 놓아보기
    for(int col = 0; col < N; col++)
    {
        // 현재 위치(row, col)에 퀸을 놓을 수 있는지 확인
        if(!is_col_used[col] && !is_right_used[row + col] && !is_left_used[row - col + 1])
        {
            // 퀸을 놓았다고 표시
            is_col_used[col] = true;
            is_right_used[row + col] = true;
            is_left_used[row - col + 1] = true;

            // 다음 행으로 이동 후 재귀 호출
            solve(row + 1);

            // 백트래킹 - 퀸을 제거하고 상태를 되돌림
            is_col_used[col] = false;
            is_right_used[row + col] = false;
            is_left_used[row - col + 1] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    is_col_used.resize(N, false);
    is_right_used.resize(2 * N - 1, false);
    is_left_used.resize(2 * N - 1, false);

    solve(0);

    cout << answers << endl;

    return 0;
}