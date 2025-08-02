#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> q;
    stack<int> s;
    int n, x;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        q.push(x);
    }

    int min = 1;
    while(!q.empty()){
        if(q.front() == min){
            q.pop();
            min++;
        }
        else if(!s.empty() && s.top() == min){
            s.pop();
            min++;
        }
        else {
            s.push(q.front());
            q.pop();
        }
    }

    while(!s.empty()){
        if(s.top() != min){
            cout << "Sad\n";
            return 0;
        }
        else {
            s.pop();
            min++;
        }
    }
    cout << "Nice\n";
    return 0;
}