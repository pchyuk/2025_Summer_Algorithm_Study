/* 나의 풀이 - 박찬혁 */
/* 풀이과정 : 삼각형의 각 층별로 갈 수 있는 곳들의 최댓값을 저장해 두어서
아래층에서 계산할 때 위 층의 계산된 값을 토대로 계산해 나간다. */
/* 사용된 알고리즘 : 다이나믹 프로그래밍(DP) */
/* 링크 : https://www.acmicpc.net/problem/1932 */

#include <iostream>
using namespace std;
int tri[501][501]; // 정수 삼각형의 입력을 저장
int dp[501][501]; // 선택된 수의 합 중 최댓값을 저장

// a와 b 중 큰 수를 리턴하는 함수
int max(int a, int b){
    return a > b ? a : b; // 삼항연산자
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    // 위의 3줄은 C++에서 입출력 속도를 향상시켜주는 역할을 함.

    int n;
    cin >> n; // n 입력

    // 정수 삼각형을 입력받는다.
    // cin 부분을 별 출력 부분으로만 바꾸면 가장 간단한 별찍기 예제가 된다.
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> tri[i][j]; 
        }
    }

    // 초기값 설정
    dp[0][0] = tri[0][0];

    // 코드의 핵심 부분.
    // 삼각형을 위에서부터 내려오면서 가장 큰 합들을 저장하면서 내려온다.
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) dp[i][j] = dp[i-1][j] + tri[i][j]; // 삼각형의 왼쪽 변의 숫자라면
            else if(i==j) dp[i][j] = dp[i-1][j-1] + tri[i][j]; // 삼각형의 오른쪽 변의 숫자라면
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j]; // 둘 다 아니라면
        }
    }

    int result = 0; // 변수 초기화
    for(int i=0; i<n; i++){
        result = max(result, dp[n-1][i]); // 삼각형의 가장 아랫줄에서 가장 큰 값을 찾아 result에 저장한다.
    }
    
    cout << result << "\n"; // 정답 출력
    return 0;
}
