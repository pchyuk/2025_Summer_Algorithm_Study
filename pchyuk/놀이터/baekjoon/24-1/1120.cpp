/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : 입력받은 두 문자열의 길이를 각각 구하고, B문자열은 A문자열보다 길거나 같으므로 
B의 길이에서 A의 길이를 빼준다. 만약 뺀 값이 0이라면 두 문자열의 길이는 같은 것이다.
두 문자열의 길이의 차이만큼 반복문을 실행하는데, 이를 통해 A문자열을 통째로 한 칸씩 이동하면서
B문자열과 비교해보고, 차이값의 최솟값을 갱신해 나가는 방식으로 문제를 해결하였다.*/
/* 사용된 알고리즘 : 문자열, 브루트포스 */
/* 링크 : https://www.acmicpc.net/problem/1120 */

#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string A, B;
    cin >> A >> B;
    int len_A = A.length(); // A문자열의 길이를 구한다.
    int len_B = B.length(); // B문자열의 길이를 구한다.
    int diff = len_A; // 두 문자열의 차이를 저장할 diff배열을 A문자열의 길이로 초기화한다.
    // 차이값의 최대값이 A문자열이 길이이기 때문이고, 더 작은 값이 생기면 값을 갱신한다.

    for(int i=0; i<=len_B-len_A; i++){ // 두 문자열의 길이의 차이만큼 반복
        int tmp = 0; // 임시공간
        for(int j=i; j<i+len_A; j++){ // i부터 i+len_A까지
            if(A[j-i] != B[j]) tmp++; // 두 값이 차이가 있다면 tmp값을 올린다.
            // A배열을 한 칸씩 통째로 옮겨가면서 비교한다.
        }
        if(tmp < diff) diff = tmp; // 구한 값이 저장되어있는 차이값보다 작다면 값을 갱신한다.
    }

    cout << diff << "\n"; // 결과값 출력
    return 0;
}