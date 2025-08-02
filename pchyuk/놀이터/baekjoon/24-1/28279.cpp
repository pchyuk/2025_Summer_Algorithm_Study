#include <iostream>
#include <deque>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    deque<int> d;
    int n, order, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> order;
        if(order == 1){
            cin >> x;
            d.push_front(x);
        }
        else if(order == 2){
            cin >> x;
            d.push_back(x);
        }
        else if(order == 3){
            if(d.empty()) cout << "-1\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if(order == 4){
            if(d.empty()) cout << "-1\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if(order == 5){
            cout << d.size() << "\n";
        }
        else if(order == 6){
            cout << d.empty() << "\n";
        }
        else if(order == 7){
            if(d.empty()) cout << "-1\n";
            else cout << d.front() << "\n";
        }
        else if(order == 8){
            if(d.empty()) cout << "-1\n";
            else cout << d.back() << "\n";
        }
    }
    return 0;
}