#include <iostream>
using namespace std;
int gcd(int a, int b){
    int r = a;
    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a1, b1, a2, b2, r1, r2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    r2 = a2 * b2;
    a1 *= b2;
    b1 *= a2;
    r1 = a1 + b1;

    int R1 = r1 / gcd(r2,r1);
    int R2 = r2 / gcd(r2,r1);

    cout << R1 << " " << R2 << "\n";
    return 0;
}