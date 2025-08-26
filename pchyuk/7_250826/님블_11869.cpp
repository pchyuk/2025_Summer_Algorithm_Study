#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n); // 원소 n개의 벡터 선언 후 0으로 초기화
    
    for(int i=0; i<n; i++) cin >> v[i];
    int res = v[0];
    
    for(int i=1; i<n; i++) res ^= v[i]; // XOR 연산 - 그런디 수
    
    if(res > 0) cout << "koosaga\n"; // 그런디 수가 0이 아니라면 - 선공 승
    else cout << "cubelover\n"; // 아니라면(그런디 수가 0이라면) - 후공 승
    return 0;
}