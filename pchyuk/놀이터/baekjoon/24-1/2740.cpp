/* 나의 풀이 : 박찬혁 */
/* 풀이 과정 : 단순히 두 행렬을 곱하는 흐름대로 이차원 배열을 곱해 나간다. */
/* 사용된 알고리즘 : 수학, 구현, 선형대수학 */
/* 링크 : https://www.acmicpc.net/problem/2740 */

#include <iostream>
using namespace std;
int a[101][101]; // 입력 배열 1
int b[101][101]; // 입력 배열 2
int c[101][101]; // 출력 배열(두 행렬의 곱 저장)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m; // n과 m을 입력받고
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j]; // 행렬 입력
        }
    }

    cin >> m >> k; // m과 k를 입력받고
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            cin >> b[i][j]; // 행렬 입력
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            for(int k=0; k<m; k++){
                c[i][j] += a[i][k] * b[k][j]; // 행렬을 곱하는 방식대로 값을 계산한다.
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout << c[i][j] << " "; // 결괏값 출력
        }
        cout << "\n";
    }

    return 0;
}