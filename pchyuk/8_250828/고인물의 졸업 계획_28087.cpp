/* 나의 풀이 : 박찬혁 */
/* 풀이 과정 : */
/* 사용된 알고리즘 : 그리디 알고리즘 */
/* 링크 : https://www.acmicpc.net/problem/28087 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m); 
    // int형 변수 한 "쌍(pair)"을 입력받을 벡터(동적 배열) p를 선언 후 
    // m개의 원소를 0으로 초기화
    // 1. 과목의 학점 수와, 2. 이 과목이 몇 번째로 입력받은 것인지를 저장한다.

    for(int i=0; i<m; i++){ // m번 반복문을 돌려서
        cin >> p[i].first; // pair 쌍의 첫 번째 원소(fisrt)에 과목의 학점 수를,
        p[i].second = i + 1; // pair 쌍의 두 번째 원소(second)에 이 과목이 몇 번째로 입력받았는지를 저장한다.
        
        // 예: 만약 m = 3이고 (3개의 학점을 입력받음)
        // 순서대로 3, 1, 2를 입력받았다면
        // 벡터에는 (3,1), (1,2), (2,3)이 저장됨
    }

    sort(p.begin(), p.end()); // pair vector를 "pair의 첫 번째 원소 기준으로" 오름차순 정렬 후
    reverse(p.begin(), p.end()); // vector를 통째로 뒤집어 준다. (이러면 내림차순(큰 수가 먼저 나옴)으로 정렬됨)

    int sum = 0, cnt = 0;
    vector<int> v;

    for(int i=0; i<m; i++){
        if(sum + p[i].first <= 2*n){ // 총합 + 학점의 값이 2*n 이하라면 (upper bound 아래라면)
            sum += p[i].first; // 학점의 값을 sum값에 더해주고
            cnt++; // 카운트 값을 올려준 후에, 
            v.push_back(p[i].second); // 학점 입력 순서를 벡터에 저장해 준다
        }
        if(sum >= n) break; // 총합이 n을 넘는 순간 break
    }

    cout << cnt << "\n";
    for(int i=0; i<cnt; i++){
        cout << v[i] << "\n";
    }
    
    return 0;
}