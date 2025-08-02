#include <iostream>
#include <stack>
using namespace std;

int fibo[45];
void fibonacci(){
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<45; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    fibonacci();
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        stack<int> s;
        cin >> n;
        for(int i=44; n!=0; i--){
            if(n >= fibo[i]){
                s.push(fibo[i]);
                n -= fibo[i];
            }
        }
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }
    return 0;
}