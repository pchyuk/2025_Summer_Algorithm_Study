#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int queue[10001];
int front = -1, rear = -1;

void push(int x);
int pop();
int size();
int empty();
int front_f();
int back();

int main(){
    int command_num;
    int push_num = 0;
    string s;
    cin>>command_num;
    cin.ignore();
    for(int i = 0; i<command_num; i++){
        getline(cin, s);
        if(s == "pop"){
            cout<<pop()<<"\n";
        }
        else if(s == "size"){
            cout<<size()<<"\n";
        }
        else if(s == "empty"){
            cout<<empty()<<"\n";
        }
        else if(s == "front"){
            cout<<front_f()<<"\n";
        }
        else if(s == "back"){
            cout<<back()<<"\n";
        }
        else{
            for(int i = 0; i<s.length(); i++){
                if(s[i]>='0' && s[i]<='9'){
                    push_num += (s[i]-'0')*pow(10, (s.length()-1)-i);
                }
            }
            push(push_num);
            push_num = 0;
        }
    }
    return 0;
}

void push(int x){
    rear = rear + 1;
    queue[rear] = x;
}

int pop(){
    if(front == rear){
        return -1;
    }
    front+=1;
    return queue[front];
}

int size(){
    return rear-front;
}

int empty(){
    if(front == rear){
        return 1;
    }
    else{
        return 0;
    }
}

int front_f(){
    if(front == rear){
        return -1;
    }
    else{
        return queue[front+1];
    }
}

int back(){
    if(front == rear){
        return -1;
    }
    else{
        return queue[rear];
    }
}