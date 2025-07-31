#include <iostream>
#include <string>
using namespace std;

/*�⺻���� ����
��ȣ�� üũ�ϴ� ����(check)�� 0���� �ΰ� '('�� ������ 1����
')'�� ������ 1 ����. ��ȣ��  VPS�� ������ 0
������ ')'�� ������ check�� 0�� ��� 0���� ū ��츦 �����ؾ� ��
�� ������ ")))" , ")(" �̷��� ��찡 �ֱ� ������
*/

//��ȣ�� ������ �� �´��� Ȯ���ϴ� �Լ�
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