#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    set<string> s;
    string str;
    cin >> str;
    int n = str.size();
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            string sub = str.substr(i,j);
            if(s.find(sub) == s.end()) s.insert(sub);
        }
    }
    cout << s.size() << "\n";
    return 0;
}