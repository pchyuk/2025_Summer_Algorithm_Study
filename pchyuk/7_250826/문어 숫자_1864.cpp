#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string octnum;
    while(1){
        cin >> octnum;
        if(octnum == "#") break;
        int len = octnum.length();
        int sum = 0;
        int digit = len - 1;
        for(int i=0; i<len; i++){

            int num = 0;
            
            if (octnum[i] == '-') num = 0;
            else if (octnum[i] == '\\') num = 1;
            else if (octnum[i] == '(') num = 2;
            else if (octnum[i] == '@') num = 3;
            else if (octnum[i] == '?') num = 4;
            else if (octnum[i] == '>') num = 5;
            else if (octnum[i] == '&') num = 6;
            else if (octnum[i] == '%') num = 7;
            else if (octnum[i] == '/') num = -1;

            sum += num * pow(8,digit);
            digit--;
        }
        cout << sum << "\n";
    }
    return 0;
}