/* 나의 풀이 : 박찬혁 */
/* 풀이 과정 : 2차원 DP 배열에 모든 구간 합을 저장해놓은 후,
필요한 만큼 잘라서 (필요 없는 부분은 빼서) 사용한다.*/
/* 사용된 알고리즘 : 다이나믹 프로그래밍(dp), 누적 합 */
/* 링크 : https://www.acmicpc.net/problem/11660 */

#include <iostream>
using namespace std;

int arr[1025][1025]; // N x N 입력받는 배열
int dp[1025][1025]; // 누적 합을 저장할 배열

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j]; // 표를 입력받은 후에
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            // 중요 포인트 1: (1,1) 부터 (i,j) 까지의 합을 dp[i][j]에 저장해 놓는다.
        }
    }

    int x1, y1, x2, y2;
    for(int i=0; i<m; i++){ // m번 반복해서
        cin >> x1 >> y1 >> x2 >> y2; // 좌표를 입력받고
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << "\n";
        // 중요 포인트 2: 구해 놓은 누적 합에서 원하는 만큼만 잘라서 버린다!
    }

    return 0;
}