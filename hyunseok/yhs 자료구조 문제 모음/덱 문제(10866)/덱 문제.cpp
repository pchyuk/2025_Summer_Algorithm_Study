#include <iostream>
#include <cmath>
using namespace std;
int dequeue[10000];
int front = -1, rear = -1;

int main(){
    int N;
    int tmp = 0;
    string s;
    cin>>N;
    cin.ignore();
    for(int i = 0; i<N; i++){
        getline(cin, s);
        if(s == "pop_front"){
            if(front == rear){
                cout<<"-1\n";
            }
            else{   
                cout<<dequeue[++front]<<"\n";
            }
        }
        else if(s == "pop_back"){
            if(front == rear){
                cout<<"-1\n";
            }
            else{   
                cout<<dequeue[rear--]<<"\n";
            }
        }
        else if(s == "size"){
            cout<<rear-front<<"\n";
        }
        else if(s == "empty"){
            if(rear == front){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(s == "front"){
            if(rear == front){
                cout<<"-1\n";
            }
            else{
                cout<<dequeue[front+1]<<"\n";
            }
        }
        else if(s == "back"){
            if(rear == front){
                cout<<"-1\n";
            }
            else{
                cout<<dequeue[rear]<<"\n";
            }
        }
        else if(s[0] == 'p' && s[5] == 'f'){
            tmp = 0;
            for(int j = 11; j<s.length(); j++){
                if(s[j] == '0'){
                    continue;
                }
                else{
                    tmp += (s[j]-'0')*static_cast<long long>(round((pow(10,(s.length()-1-j)))));
                }
            }
            if(front == -1){
                if(rear == -1){
                    dequeue[++rear] = tmp;
                }
                else{
                    for(int k = ++rear; k>front+1; k--){
                        dequeue[k] = dequeue[k-1];
                    }
                    dequeue[front+1] = tmp;
                }
            }
            else{
                dequeue[front--] = tmp;
            }
        }
        else{
            tmp = 0;
            for(int j = 10; j<s.length(); j++){
                if(s[j] == '0'){
                    continue;
                }
                else{
                    tmp += (s[j]-'0')*static_cast<long long>(round((pow(10,(s.length()-1-j)))));
                }
            }
            dequeue[++rear] = tmp;
        }
    }
    return 0;
}