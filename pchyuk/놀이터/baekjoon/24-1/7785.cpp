#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

set<string, greater<string>> s;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string name;
    string log;
    for(int i=0; i<n; i++){
        cin >> name >> log;
        if(log == "enter") s.insert(name);
        else if(log == "leave") s.erase(name);
    }
    for(auto i=s.begin(); i!=s.end(); i++){
        cout << *i << "\n";
    }
    return 0;
}