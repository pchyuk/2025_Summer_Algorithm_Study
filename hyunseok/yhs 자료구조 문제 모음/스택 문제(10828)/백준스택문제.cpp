#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int top = -1;
void push(int *tmp, int num);
void pop(int *tmp);
void size(int *tmp);
void empty(int *tmp);
void top_f(int *tmp);

int main(){
    int *stack;
    double num_to_stack = 0;
    int command_num;
    string command;
    cin>>command_num;
    cin.ignore();
    stack = new int[command_num];
    for(int i = 0; i<command_num; i++){
        getline(cin, command);
        if(command == "pop"){
            pop(stack);
        }
        else if(command == "size"){
            size(stack);
        }
        else if(command == "empty"){
            empty(stack);
        }
        else if(command == "top"){
            top_f(stack);
        }
        else{
            for(int i = 0; i<command.length(); i++){
                if(command[i]>='0' && command[i]<='9'){
                    num_to_stack +=(command[i]-'0')*(pow(10, ((command.length()-1)-i)));
                }
            }
            push(stack, num_to_stack);
            num_to_stack = 0;
        }
    }
    delete[] stack;
    return 0;
}

void push(int *tmp, int num){
    tmp[++top] = num;
}

void pop(int *tmp){
    if(top == -1){
        cout<<-1<<"\n";
    }
    else{
        cout<<tmp[top--]<<"\n";
    }
}

void size(int *tmp){
    cout<<(top+1)<<"\n";
}

void empty(int *tmp){
    if(top == -1){
        cout<<1<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
}

void top_f(int *tmp){
    if(top == -1){
        cout<<-1<<"\n";
    }
    else{
        cout<<tmp[top]<<"\n";
    }
}