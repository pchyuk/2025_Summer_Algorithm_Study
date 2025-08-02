#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        cout << s[0];
        for(int j=1; j<s.length(); j++){
            if(s[j-1] != s[j]) cout << s[j];
        }
        cout << "\n";
    }

    return 0;
}