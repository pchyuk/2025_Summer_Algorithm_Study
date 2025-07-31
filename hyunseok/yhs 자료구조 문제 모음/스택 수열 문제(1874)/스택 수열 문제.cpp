#include <iostream>
#include <string>
using namespace std;
int stack[100000];
int tmp_stack[100000];
string s;
int top = -1;

//�˰��� ���̵��
/*
    �־��� �������� ������������ push��. pop�� �־��� �Է´�� ���ʴ�� pop��.
    �׷��� �Է¿��� ���� pop�� ���� �� ���� pop�� �� ���� ũ�� ���� pop�ϱ� ���� push�� �ߴٴ� ��
    �ƴϸ� �׳� pop.
*/

int main(){
    int N;
    int tmp;
    int max_num = 0;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>stack[i];
    }

    for(int i = 0; i<N; i++){
        if(i == 0){
            max_num = stack[i];
            for(int j = 0; j<stack[i]; j++){
                tmp_stack[++top] = j+1;
                s.push_back('+');
            }
            s.push_back('-');
            if(stack[i] != tmp_stack[top--]){
                cout<<"NO";
                return 0;
            }
        }
        else if(i == N-1){
            s.push_back('-');
            if(stack[i] != tmp_stack[top--]){
                cout<<"NO";
                return 0;
            }
        }
        else if(stack[i - 1] < stack[i]){
            for(int j = max_num+1; j<=stack[i]; j++){
                tmp_stack[++top] = j;
                s.push_back('+');
            }
            s.push_back('-');
            max_num = stack[i];
            if(stack[i] != tmp_stack[top--]){
                cout<<"NO";
                return 0;
            }
        }
        else if(stack[i - 1] > stack[i]){
            s.push_back('-');
            if(stack[i] != tmp_stack[top--]){
                cout<<"NO";
                return 0;
            }
        }
    }

    for(int i = 0; i<s.length(); i++){
        cout<<s[i]<<"\n";
    }
    return 0;
}