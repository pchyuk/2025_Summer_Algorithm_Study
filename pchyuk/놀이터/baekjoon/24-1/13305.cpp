/* 나의 풀이 - 박찬혁 */

/* 풀이 과정 : road 배열에 다음 정류장까지 가는데 몇 리터의 기름이 필요한지를 저장하고,
oil 배열에 리터당 기름 가격을 저장한다. 한 주유소에 도착할 때마다 지금까지 거쳐온 주유소 중에서
가장 저렴한 주유소 가격을 min 변수에 저장하고, 다음 주유소까지 가기 위한 금액을 cost 변수에 누적해서 더해준다. */

/* 특이사항 : 이 문제를 해결하기 위해서는 크게 2가지를 고려해야 한다.
1. 주유소의 리터당 가격은 1원부터 10억원 사이여서 int 범위에 들어오지만, 그 가격에 거리를 곱해서 계속 더한 값을
저장해 줘야 하는 변수는 int형 범위보다 훨씬 커진다. 따라서 cost 변수를 long long형으로 설정해 줘야 만점을 받을 수 있다.
2. '전체 주유소' 중에서 최솟값을 구해 min에 저장하는 것이 아니라, 범위를 늘려가면서 최솟값을 찾아줘야 한다.
처음에 생각했을 때는 제일 싼 주유소가 나올 때까지 필요한 만큼만 주유하다가, 최솟값이 나오면 나머지 남은 거리만큼 필요한
모든 기름을 한 번에 주유한다고 생각했는데, 이러면 논리적으로 오류가 발생한다.
추가적으로, 문제를 분석해 보면 알겠지만, 가장 마지막에 있는 주유소는 아무 쓸모가 없다. 구글링에 따르면,
이 마지막 주유소를 입력받지 않아도 아무 문제가 생기지 않는다고 한다. 당연히 계산할 때도 고려할 필요가 없다. */

/* 알고리즘 분류 - 그리디 알고리즘 */
/* 링크 : https://www.acmicpc.net/problem/13305 */

#include <iostream>
using namespace std;

int road[100001];
int oil[100001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    long long cost = 0;
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> road[i]; // 다음 주유소까지 몇 리터가 필요한지 입력(도로의 길이)
    }

    for(int i=0; i<n-1; i++){ // 반복문을 n번이 아닌 n-1번을 돌렸다. 마지막 주유소의 입력을 무시했다.
        cin >> oil[i];  
    }
    long long min = oil[0];

    for(int i=0; i<n-1; i++){
        if(min > oil[i]) min = oil[i]; // 그때 그때 최솟값을 갱신해 가면서
        cost += min*road[i]; // 다음 주유소까지 필요한 기름을 주유한다.
        // 만약 min 변수가 int형이었다면, int*int를 했을 때 이미 오버플로우가 발생하고,
        // 그 결과값이 long long형인 cost에 들어간다 한들 잘못된 계산값이 나올 것이다.
        // 따라서 min 변수도 long long형이 되어야 하고 road[i]는 long long형으로 자동 형변환이 된다.
    }
    cout << cost << "\n";
    return 0;
}

// 틀린 코드 1
// 위에 서술한 특이사항 1번 참조. 이대로 제출하면 서브태스크 1,2번만 만족하여 58점이 나온다.
// 코드에 있는 모든 int형을 long long으로 바꿔줘도 되지만, 100001개의 원소를 가진 배열까지 long long형으로 바꿔줄 필요는 없다.
// 메모리를 아끼자
#include <iostream>
using namespace std;

int road[100001];
int oil[100001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int cost = 0; // 이 부분을 long long형으로 바꿔주면 된다.
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> road[i];
    }

    for(int i=0; i<n-1; i++){
        cin >> oil[i];  
    }
    int min = oil[0]; // 이 부분을 long long형으로 바꿔주면 된다.

    for(int i=0; i<n-1; i++){
        if(min > oil[i]) min = oil[i];
        cost += min*road[i];
    }
    cout << cost << "\n";
    return 0;
}

// 틀린 코드 2
// 위에 서술한 특이사항 2번 참조. 이대로 제출하면 서브태스크 1번만 만족하여 17점이 나온다.
#include <iostream>
using namespace std;

long long road[100001];
long long oil[100001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long n, sum = 0; // sum 변수 추가
    long long cost = 0;
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> road[i];
        sum += road[i]; // 도로의 전체 길이를 구한다.
    }

    for(int i=0; i<n-1; i++){
        cin >> oil[i];  
    }
    long long min = oil[0];
    for(int i=0; i<n-1; i++){
        if(min > oil[i]) min = oil[i]; // 전체 주유소 중에서 최솟값을 구한다.
    }

    for(int i=0; sum != 0; i++){ // 도로의 길이가 0이 될때까지 반복
        if(oil[i] == min){ // 이 주유소가 제일 싼 곳이라면
            cost += oil[i]*sum; // 남은 거리만큼 모두 주유한다.
            sum = 0;
        }
        else { // 그렇지 않다면(주유소가 제일 싼 곳이 아니라면)
            cost += oil[i]*road[i]; // 다음 주유소까지 갈 만큼만 주유하고
            sum -= road[i]; // 이동한 거리만큼 빼준다.
        }
    }
    cout << cost << "\n";
    return 0;
}

