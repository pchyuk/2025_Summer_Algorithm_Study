/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : n개의 원소를 가진 배열을 만들고, 이 배열을 원형 큐처럼 사용하여
원소의 값에 접근하고 삭제한다. */
/* 사용된 알고리즘 : 구현, 자료구조, 큐 */
/* 링크 : https://www.acmicpc.net/problem/1158 */

#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k; // n과 k를 입력받고
    int jump = k; // k값을 jump에 복사한다 - 나중에 0인 값을 제외하고 k번을 뛰기 위함

    int arr[n]; // n개의 원소를 가진 배열 생성 - 원형 큐 역할
    for(int i=0; i<n; i++){
        arr[i] = i+1; // 큐에 값을 집어넣는다.
    }

    cout << "<";
    k--; // 출력 형식을 맞추기 위한 k값 수정 - 마지막 값은 따로 출력하기 위함
    
    for(int i=0; i<n-1; i++){
        cout << arr[k%n] << ", "; // k를 n으로 나눈 나머지를 인덱스로 하여 배열에 접근 - 모듈로 연산을 통한 원형 큐 구현
        arr[k%n] = 0; // 해당 값을 출력했으면(사람을 제거했다면) 해당 위치를 0으로 바꾼다
        int count = 0; // 점프한 횟수를 카운트하기 위한 변수 선언
        while(count < jump){ // count 횟수가 jump(=처음에 입력한 k번)보다 작을때 반복
            if(arr[++k%n] != 0) count++; // 배열의 값이 0이 아닐 때만 count증가, k값도 증가
        }
    }
    cout << arr[k%n] << ">\n"; // 마지막 남은 값까지 출력하고
    return 0; // 프로그램 종료
}