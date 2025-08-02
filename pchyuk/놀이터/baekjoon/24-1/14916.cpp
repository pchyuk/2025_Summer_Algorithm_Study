#include <iostream>
using namespace std;

int money[100001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    money[1] = -1;
    money[2] = 1;
    money[3] = -1;
    money[4] = 2;
    money[5] = 1;
    for(int i=6; i<=n; i++){
        if(money[i-5] != -1) money[i] = money[i-5] + 1;
        else if(money[i-2] != -1) money[i] = money[i-2] + 1;
        else money[i] = -1;
    }
    cout << money[n] << "\n";
    return 0;
}