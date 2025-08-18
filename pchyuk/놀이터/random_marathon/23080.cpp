#include <iostream>
#include <string>
using namespace std;

int main(){
    int k;
    string s;
    cin >> k >> s;

    int len = s.length();
    for(int i=0; i<len; i+=k){
        cout << s[i];
    }
    cout << "\n";
    return 0;
}