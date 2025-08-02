#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    int num = 666;
    while(1){
        int tmp = num;
        while(tmp != 0){
            if(tmp % 1000 == 666){
                cnt++;
                break;
            }
            else{
                tmp /= 10;
            }
        }
        if(cnt==n) break;
        num++;
    }
    cout << num << "\n";
    return 0;
}