/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : 파스칼의 공식을 이용하여 dp 방식으로 값을 계산하여 출력한다. */
/* 사용된 알고리즘 : dp, 조합론 */
/* 링크 : https://www.acmicpc.net/problem/16395 */

#include <iostream>
using namespace std;

int pascal[31][31]; // 파스칼의 삼각형 값을 저장할 2차원 배열

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        pascal[i][1] = 1; // 삼각형의 첫번째 줄과
        pascal[i][i] = 1; // 삼각형의 마지막 줄은 항상 1이다.
    }

    for(int i=3; i<=n; i++){
        for(int j=2; j<i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]; // 파스칼의 삼각형 공식 적용
        }
    }

    cout << pascal[n][k] << "\n"; // 출력
    return 0;
}
