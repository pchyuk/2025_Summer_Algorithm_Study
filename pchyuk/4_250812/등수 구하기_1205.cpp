/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : 점수를 저장할 score 배열을 선언하고, 새 점수와 기존 점수를 비교해 가면서
새 점수가 기존 점수보다 '높을 때만' rank값을 증가시킨다. 만약 랭킹 리스트에 올라갈 수 있는
점수의 개수인 p개보다 점수가 낮아서 루프를 다 돌 동안에 프로그램이 종료되지 않았다면 -1을 출력한다.*/

/* 특이사항 : 처음에는 등수를 출력하는 조건에 new_score > score[i] 조건만 있었는데, 
이대로 답을 제출하니까 62%에서 오답이 나왔다. 거의 대부분의 조건에서 코드가 잘 동작해서
어느 부분이 틀렸는지 찾는데 조금 애를 먹었는데, 만약 new_score값이 0이라면, score배열은 
기본적으로 0으로 초기화되어있기 때문에 new_score값과 기존의 score값이 0으로 같게 되어서
루프를 빠져나오지 못하게 되는 문제가 있었다. 그래서 score 배열의 값이 0일 때에도 등수를
출력하게 하여서 문제를 해결하였다.*/

/* 사용된 알고리즘 : 구현 */
/* 링크 : https://www.acmicpc.net/problem/1205 */

#include <iostream>
using namespace std;

int score[51];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, new_score, p, rank = 1;
    cin >> n >> new_score >> p;
    if(n == 0){ // 저장되어 있는 점수가 없다면
        cout << "1\n"; // 내가 무조건 1등!
        return 0; // 프로그램을 종료합니다.
    }

    for(int i=0; i<n; i++){
        cin >> score[i]; // n개의 점수를 입력받는다.
    }

    for(int i=0; i<p; i++){
        if(new_score > score[i] || score[i] == 0){ // 새 점수가 i번째 점수보다 높거나 기존 점수가 0점이면
            cout << rank << "\n"; // 현재의 등수를 출력해주고
            return 0; // 프로그램 종료
        }
        else if(new_score < score[i]) rank++; // 새 점수가 i번째 점수보다 낮다면 rank값을 1 증가시킨다.
        // 만약 새 점수랑 i번째 점수랑 같다면? rank를 올려주지 않는다!(아무것도 안한다.)
    }
    cout << "-1\n"; // 루프를 다 돌고 나왔다면(내 점수가 순위 안에 못 들었다면) -1 출력
    return 0;
}
