#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    
    int flag;
    for(int i=0; i<s.size(); i++){
        if(s[i]!='0'){
            flag = i;
            break;
        }
    }
    for(int i=flag; i<s.size(); i++){
        cout << s[i];
    }
    cout << "\n";

    int sum=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            sum += (s[i]-'0');
        }
    }
    cout << sum << "\n";
    return 0;
}