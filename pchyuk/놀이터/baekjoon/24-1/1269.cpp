#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    int num;
    cin >> n >> m;
    for(int i=0; i<n+m; i++){
        cin >> num;
        if(s.find(num) == s.end()) s.insert(num);
        else s.erase(num);
    }
    cout << s.size() << "\n";
    return 0;
}
