#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, count = 99;
    cin >> n;
    if(n<100){
        cout << n << "\n";
        return 0;
    }
    if(n>=111) count++;
    if(n>=123) count++;
    if(n>=135) count++;
    if(n>=147) count++;
    if(n>=159) count++;

    if(n>=210) count++;
    if(n>=222) count++;
    if(n>=234) count++;
    if(n>=246) count++;
    if(n>=258) count++;

    if(n>=321) count++;
    if(n>=333) count++;
    if(n>=345) count++;
    if(n>=357) count++;
    if(n>=369) count++;

    if(n>=420) count++;
    if(n>=432) count++;
    if(n>=444) count++;
    if(n>=456) count++;
    if(n>=468) count++;

    if(n>=531) count++;
    if(n>=543) count++;
    if(n>=555) count++;
    if(n>=567) count++;
    if(n>=579) count++;

    if(n>=630) count++;
    if(n>=642) count++;
    if(n>=654) count++;
    if(n>=666) count++;
    if(n>=678) count++;

    if(n>=741) count++;
    if(n>=753) count++;
    if(n>=765) count++;
    if(n>=777) count++;
    if(n>=789) count++;

    if(n>=840) count++;
    if(n>=852) count++;
    if(n>=864) count++;
    if(n>=876) count++;
    if(n>=888) count++;

    if(n>=951) count++;
    if(n>=963) count++;
    if(n>=975) count++;
    if(n>=987) count++;
    if(n>=999) count++;
    
    cout << count << "\n";
    return 0;
}