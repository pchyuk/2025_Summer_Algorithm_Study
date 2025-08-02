#include <iostream>
#include <stack>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    stack<int> s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int order, x;
        cin >> order;
        if(order == 1){
            cin >> x;
            s.push(x);
        }
        else if(order == 2){
            if(s.empty() == 1) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(order == 3){
            cout << s.size() << "\n";
        }
        else if(order == 4){
            cout << s.empty() << "\n";
        }
        else if(order == 5){
            if(s.empty() == 1) cout << -1 << "\n";
            else cout << s.top() << "\n";
        }
    }
    return 0;
}