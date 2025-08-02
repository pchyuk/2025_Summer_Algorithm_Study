#include <iostream>
using namespace std;
int fibo(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibo(n-1) + fibo(n-2);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fibo(n) << "\n";
    return 0; 
}