#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string tmp;
    vector<string> s;
    vector<char> stack;
    int check = 0;
    while(true){
        getline(cin, tmp);
        if(tmp == "."){
            break;
        }
        s.push_back(tmp);
    }

    for(const string& currentString : s){
        stack.clear();
        check = 1;
        for(char character : currentString){
            if(character == '('){
                stack.push_back('(');
                continue;
            }
            else if(character == ')' && stack.empty() != true){
                if(stack.back() != '(' ){
                    check = 0;
                    break;
                }
                else{
                    stack.pop_back();
                    continue;
                }
            }
            else if(character == ')' && stack.empty() == true){
                check = 0;
                break;
            }
            if(character == '['){
                stack.push_back('[');
                continue;
            }
            else if(character == ']' && stack.empty() != true){
                if(stack.back() != '['){
                    check = 0;
                    break;
                }
                else{
                    stack.pop_back();
                }
                continue;
            }
            else if(character == ']' && stack.empty() == true){
                check = 0;
                break;
            }
        }
        if(stack.empty() == true && check != 0){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}