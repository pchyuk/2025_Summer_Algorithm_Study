#include <iostream>
using namespace std;

string solution(string str, int k){
    string result="";
    for(int i=0; i<k; i++){
        result+=str;
    }
    return result;
}

int main(){
    string a;
    int b;
    cin >> a >> b;
    cout << solution(a,b) << "\n";
    return 0;
}