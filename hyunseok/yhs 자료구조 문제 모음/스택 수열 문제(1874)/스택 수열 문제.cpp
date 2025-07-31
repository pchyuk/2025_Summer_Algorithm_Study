#include <iostream>
#include <string>
using namespace std;
int stack[100000];
int tmp_stack[100000];
string s;
int top = -1;

//알고리즘 아이디어
/*
    주어진 문제에선 오름차순으로 push함. pop은 주어진 입력대로 차례대로 pop함.
    그러면 입력에서 현재 pop한 수가 그 전에 pop한 수 보다 크면 현재 pop하기 전에 push를 했다는 뜻
    아니면 그냥 pop.
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