/* 나의 풀이 - 박찬혁 */
/* 풀이 과정 : wine 배열에는 입력값을 넣고, dp 배열에는 잔이 i개 있을 때의 최댓값을 저장해 나간다. */
/* 사용된 알고리즘 : 다이나믹 프로그래밍(DP) */
/* 특이사항 : 처음에는 i번째 잔을 '무조건' 마신다고 가정하고 dp 배열을 채웠고, 
나중에 dp값들 중에서 가장 큰 값을 출력했다. 이럴 경우 예제 케이스는 통과하지만, 
입력이 1 1 0 0 1 1과 같이 들어왔을 때 오답을 출력한다. */
/* 링크 : https://www.acmicpc.net/problem/2156 */

#include <iostream>
using namespace std;

// a,b,c 중에서 제일 큰 수를 반환
int max(int a, int b, int c){
    int tmp;
    tmp = a > b ? a : b; // a, b중에서 큰 수를 tmp에 저장한 후에
    return tmp > c ? tmp : c; // tmp와 c 중에서 큰 수를 반환한다.
    // algorithm 헤더를 이용하면 max 함수를 사용하여 3개 이상의 수 중에서 최댓값을 찾을 수 있다.
}

int wine[10001]; // 입력값을 저장하는 배열
int dp[10001]; // 최선의 합을 저장하는 배열
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> wine[i]; // 값을 입력받는다.
    }

    dp[1] = wine[1]; // 잔이 1개일때는 1개를 마시는게 최선
    dp[2] = wine[1] + wine[2]; // 잔이 2개일 때는 둘 다 마시는게 최선

    // 잔이 3개일 때는, 3개의 잔을 연속해서 마시지 못하기 때문에 양이 많은 2개를 마신다.
    dp[3] = max(wine[1] + wine[2], wine[2] + wine[3], wine[1] + wine[3]);

    // 코드의 핵심
    // 잔이 4개 이상일 때부터는
    // 1. 잔이 i-1개일 때 최대로 마실수 있는 양을 마신다.
    // 2. i번째 잔과 i-1번째 잔을 마시고, 잔이 i-3개일 때 최대로 마실 수 있는 양을 마신다.
    // 3. i번째 잔을 마시고, 잔이 i-2개일 때 최대로 마실 수 있는 양을 마신다.
    // 1,2,3번 케이스 중에서 가장 많은 양을 마실 수 있는 양을 마신다.
    for(int i=4; i<=n; i++){
        dp[i] = max(dp[i-1], wine[i] + wine[i-1] + dp[i-3], wine[i] + dp[i-2]);
    }
    
    cout << dp[n] << "\n"; // 잔이 n개일 때의 최선을 출력
    return 0;
}

// 아래는 틀린 답안
#include <iostream>
using namespace std;
int max(int a, int b){
    return a > b ? a : b; // 둘 중 큰 수 반환
}
int wine[10001];
int dp[10001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    // 정답 코드와 차이점 1
    // 3번째 잔을 무조건 마셔야 한다고 생각했기 때문에, 1번 잔과 2번 잔 중 큰 것을 골라 마시고 3번을 마신다고 생각했다.
    // 정답 코드는 아래 2가지 경우에서 1,2번 잔을 마시는 경우의 비교가 추가되었다.
    dp[3] = max(wine[1], wine[2]) + wine[3];

    // 정답 코드와 차이점 2
    // i번째 잔을 무조건 마셔야 한다고 생각했다.
    // 정답 코드는 아래 2가지 경우에서 dp[i-1]과의 비교가 추가되었다.
    for(int i=4; i<=n; i++){
        dp[i] = max(wine[i-1] + dp[i-3], dp[i-2]) + wine[i];
    }
    int result = 0;

    // 이 코드의 경우, dp[n]의 값이 제일 크다는 보장이 없기 때문에
    // 반복문을 통해 dp 배열의 원소들 중 최댓값을 찾아 출력해 주었다.
    for(int i=1; i<=n; i++){
        result = max(result, dp[i]);
    }
    cout << result << "\n";
    return 0;
}
