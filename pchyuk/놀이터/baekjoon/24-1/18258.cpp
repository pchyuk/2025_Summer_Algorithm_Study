#include <iostream>
#include <queue>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue<int> q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string order;
        cin >> order;
        if(order == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(order == "pop"){
            if(q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(order == "size"){
            cout << q.size() << "\n";
        }
        else if(order == "empty"){
            cout << q.empty() << "\n";
        }
        else if(order == "front"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(order == "back"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}