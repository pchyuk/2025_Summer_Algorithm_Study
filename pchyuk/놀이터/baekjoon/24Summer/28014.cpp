#include <iostream>
using namespace std;
int top[5000000];
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> top[i];
    }
    int count = 1;
    for(int i=1; i<n; i++){
        if(top[i-1]<=top[i]) count++;
    }
    cout << count << "\n";
    return 0;
}