#include <iostream>
using namespace std;

long long int euclidian(long long int a, long long int b){
    int r = a;
    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long int a, b;
    cin >> a >> b;
    cout << a*b / euclidian(a,b) << "\n";
    return 0;
}