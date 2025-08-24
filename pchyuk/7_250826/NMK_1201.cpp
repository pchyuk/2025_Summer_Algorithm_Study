#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    // 최대 부분 증가 수열과 최대 부분 감소 수열은 하나의 원소만 공유
    // n = m * k + 1인 경우: 길이가 m + 1인 증가 수열과 길이가 k + 1인 감소 수열을 만들 수 있음
    if(m + k - 1 <= n && n <= m * k){
        vector<int> arr(n); // 벡터 원소를 n개만큼 생성 후 0으로 초기화
        for(int i=0; i<n; i++) arr[i] = i + 1;

        
        int index = 0; // 하나의 그룹 시작 인덱스
        for(int i=1; i<=m; i++){ // m개의 그룹으로 나눈다
            // 각 그룹에 들어있는 수는 k보다 작거나 같아야 하고
            // 주어진 조건을 만족시키기 위해서 한 그룹은 k개의 수를 가지고 있다.
            int tmp = min(index + k, n - m + i);
            reverse(arr.begin() + index, arr.begin() + tmp); // 각 그룹을 뒤집어준다.
            index = tmp;
        } 

        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}