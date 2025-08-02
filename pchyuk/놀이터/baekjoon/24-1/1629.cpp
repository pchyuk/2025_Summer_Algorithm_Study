#include <iostream>
using namespace std;
long long modulo(int a, int b, int c){
    if(b == 1) return a % c;
    else if(b % 2 == 0){
        long long n = modulo(a, b/2, c);
        return n * n % c;
    }
    else return (modulo(a, b-1, c) * (a%c)) % c;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, c, tmp;
    cin >> a >> b >> c;
    cout << modulo(a, b, c) << "\n";
    return 0;
}