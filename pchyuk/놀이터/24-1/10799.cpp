/* 나의 풀이 - 박찬혁 */ 
/* 풀이 과정 : string 형태로 입력값을 입력받고, 총 3가지의 경우에 따라 계산한다.
1. i번째 값이 '(' 라면? : 막대의 시작이거나 레이저의 시작이므로 count 값을 1 올려준다.(스택에 push)
2. i번째 값이 ')'인데, 이전 값(i-1번째 값)이 '(' 이라면? : ()이므로 레이저를 뜻한다.
   sum 변수에 지금껏 저장해 두었던 count 값을 더해준다.(막대를 잘라서 앞부분의 개수만큼 추가시킨다.)
3. i번째 값이 ')'인데, 이전값도 ')'이라면? : 막대 하나가 끝난 것이므로 sum 값을 하나 증가시킨다.(막대 꼬다리 추가)
*/
/* 특이사항 : 입력이 괄호로 주어지는 것을 보고 계속 괄호 쌍을 찾아야 한다고 생각했는데, 이렇게 풀려고 하니까 
도저히 문제가 풀리지 않았다. 인터넷을 조금 찾아보니까 생각보다 너무 단순하게 풀려서 놀랐다.
입력으로 '('이 들어올 때는 push, ')'이 들어올 때는 pop을 해 주는 것까지는 생각할 수 있었지만, 
()이 동시에 나올 때 push해둔 값을 sum에 저장한다는 아이디어와 ))이 나온 경우 뒤의 괄호는 
막대 하나가 끝났다는 뜻이라는 것은 생각하지 못했다. */
/* 사용된 알고리즘 : 스택 */
/* 링크 : https://www.acmicpc.net/problem/10799 */

#include <iostream>
#include <string>
using namespace std;

int main(){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int count = 0;
    int sum = 0;

    string pipe;
    cin >> pipe;

    int len = pipe.length();
    for(int i=0; i<len; i++){
        if(pipe[i] == '(') count++; // 1번 경우
        else { // i번째 값이 ')'인 경우우
            count--; // 2,3번 경우 둘다 count 값은 하나 빼줘야 한다.
            if(pipe[i-1] == '(') sum += count; // 2번 경우(레이저 발사)
            else sum++; // 3번 경우(막대의 종료)
        }
    }
    cout << sum << "\n"; // 결괏값 출력
    return 0;
}