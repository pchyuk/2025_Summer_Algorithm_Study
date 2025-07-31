#include <iostream>
#include <string>
using namespace std;

/*기본적인 개념
괄호를 체크하는 변수(check)를 0으로 두고 '('를 만나면 1증가
')'를 만나면 1 감소. 괄호가  VPS면 무조건 0
하지만 ')'를 만날때 check가 0인 경우 0보다 큰 경우를 구별해야 함
그 이유는 ")))" , ")(" 이러한 경우가 있기 때문에
*/

//괄호가 쌍으로 잘 맞는지 확인하는 함수
bool calculate(string *tmp){
    int check = 0;
    for(int i = 0; i<(*tmp).length(); i++){
        if((*tmp)[i] == '('){
            check++;
        }
        else if(check > 0 && (*tmp)[i] == ')'){
            check--;
        }
        else if(check == 0 && (*tmp)[i] == ')'){
            return false;
        }
    }
    if(check == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int test_data = 0;
    string s;
    cin>>test_data;
    cin.ignore();
    for(int i = 0; i<test_data; i++){
        getline(cin, s);
        if(calculate(&s) == true){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}