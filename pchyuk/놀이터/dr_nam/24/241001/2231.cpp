#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum, num, digit;
    cin >> n;
    for(int i=1; i<=n; i++){
        digit = i;
        sum = 0;
        sum += i;

        while(digit > 0){
            sum += digit%10;
            digit /= 10;
        }
        if(sum == n) {
            cout << i << "\n";
            return 0;
        }
        if(i==n) cout << 0 << "\n";
    }
    return 0;
}