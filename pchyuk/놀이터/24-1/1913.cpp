/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : 달팽이의 중심에서부터 시작해서 rotate값이 홀수인지 짝수인지에 따라 
2차원 배열의 탐색 위치를 바꿔간다. */
/* 사용된 알고리즘 : 구현 */
/* 링크 : https://www.acmicpc.net/problem/1913 */

#include <iostream>
using namespace std;
int snail[1000][1000];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, rotate = 1, count = 1;
    cin >> n;

    int center = (n+1)/2; // 달팽이의 중심값
    int x = center;
    int y = center;
    snail[x][y] = 1; // 달팽이의 중심에는 1이 있다.

    while(x>=1 && x<=n && y>=1 && y<=n){ // 달팽이가 범위 내에 있을 때
        if(rotate % 2 == 1){ // rotate 값이 홀수라면
            for(int i=0; i<rotate; i++) snail[--x][y] = ++count; // 위로 한칸
            for(int i=0; i<rotate; i++) snail[x][++y] = ++count; // 오른쪽으로 한칸
            rotate++; // rotate값 증가
        }
        else {
            for(int i=0; i<rotate; i++) snail[++x][y] = ++count; // 아래로 한칸
            for(int i=0; i<rotate; i++) snail[x][--y] = ++count; // 왼쪽으로 한칸
            rotate++; // rotate값 증가
        }
    }

    int find;
    int a, b;
    cin >> find;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){ // 2중 for문을 돌면서
            if(find == snail[i][j]){ // 찾고자 하는 값을 찾으면
                a = i;
                b = j;
            }
            cout << snail[i][j] << " "; // 해당 위치에 있는 달팽이값 출력
        }
        cout << "\n";
    }
    
    cout << a << " " << b << "\n";
    return 0;
}