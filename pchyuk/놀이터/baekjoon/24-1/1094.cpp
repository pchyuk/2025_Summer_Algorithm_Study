#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int x, remain, count = 1;
    cin >> x;
    while(x > 1){
        remain = x % 2;
        if(remain == 1) count++;
        x /= 2;
    }
    cout << count << "\n";
    return 0;
}