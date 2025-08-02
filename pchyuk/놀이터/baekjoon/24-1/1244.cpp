/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : 문제의 조건에 따라서 배열을 탐색하고 값을 바꿔준다. */
/* 사용된 알고리즘 : 구현, 시뮬레이션 */
/* 링크 : https://www.acmicpc.net/problem/1244 */

#include <iostream>
using namespace std;
int arr[101];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, student, gender, num;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    cin >> student;
    for(int i=0; i<student; i++){
        cin >> gender >> num;
        if(gender == 1){ // 남학생
            for(int i=1; num*i <= n; i++){ // 스위치 번호가 받은 수의 배수이면
                if(arr[num*i] == 0) arr[num*i] = 1; // 스위치가 꺼져 있다면 켜고
                else if(arr[num*i] == 1) arr[num*i] = 0; // 스위치가 켜져 있다면 끈다.
            }
        }
        else if(gender == 2){ // 여학생
            for(int i=0; num-i>0 && num+i<=n; i++){ // 찾는 스위치가 범위 안에 있다면
                if(arr[num+i] == arr[num-i]){ // num을 중심으로 i만큼 떨어진 두 값이 같다면
                    if(arr[num+i] == 0) arr[num+i] = arr[num-i] = 1; // 스위치가 꺼져 있다면 켜고
                    else if(arr[num-i] == 1) arr[num+i] = arr[num-i] = 0; // 스위치가 켜져 있다면 끈다.
                }
                else break;
            }
        }
    }

    int count = 0;
    while(n > 20){ // 스위치가 20개보다 크다면
        for(int i=count+1; i<=count+20; i++){
            cout << arr[i] << " "; // 20개씩 끊어서 출력
        }
        cout << "\n";
        count += 20;
        n -= 20;
    }
    for(int i=count+1; i<=count+n; i++){ 
        cout << arr[i] << " "; // 남은 스위치 출력
    }
    cout << "\n";
    return 0;
}