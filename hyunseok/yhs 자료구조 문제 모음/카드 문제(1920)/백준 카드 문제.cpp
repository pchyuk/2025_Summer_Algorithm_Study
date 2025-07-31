#include <iostream>
using namespace std;

int main(){
    int queue[500001];
    int front = -1, rear = -1;
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        rear = (rear+1)%500001;
        queue[rear] = i+1;
    }
    for(int i = 0; (front+1)%500001 != (rear)%500001; i++){
        if(i%2 == 0){
            front = (front+1)%500001;
        }
        else{
            rear = (rear+1)%500001;
            front = (front+1)%500001;
            queue[rear] = queue[front];
        }
    }
    cout<<queue[rear];
    return 0;
}