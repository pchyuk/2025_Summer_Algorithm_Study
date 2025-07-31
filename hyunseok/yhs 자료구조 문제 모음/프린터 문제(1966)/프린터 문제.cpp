#include <iostream>
using namespace std;

//큐 사용
int queue[10000];
int front = -1, rear = -1;

int main(){
    int N, M, T;
    //check는 문서 중요도 크기 판별
    //order는 출력 순서
    int check, order = 0;
    cin>>T;
    for(int i = 0; i<T; i++){
        front = -1, rear= -1;
        order = 0;
        cin>>N;
        cin>>M;
        //문서 중요도 입력
        //문제에서 출력하고자 하는 문서를 구별하기 위해 중요도에 9더함
        for(int j = 0; j<N; j++){
            cin>>queue[++rear];
            if(j == M){
                queue[rear] += 9;
            }
        }
        //문서 출력 순서 판별
        while(front != rear){
            check = 0;
            //문서 중요도 크기 판별
            for(int k = front+2; k<=rear; k++){
                if(queue[k]>9){
                    if(queue[front+1] < (queue[k]-9)){
                        queue[++rear] = queue[++front];
                        check++;    
                    }
                }
                else if(queue[front+1]>9){
                    if((queue[front+1]-9) < queue[k]){
                        queue[++rear] = queue[++front];
                        check++;    
                    }
                }
                else if(queue[front+1] < queue[k]){
                    queue[++rear] = queue[++front];
                    check++;
                }
            }
            if(check == 0){
                order++;
                if(queue[front+1]>9){
                    cout<<order<<"\n";
                    break;
                }
                else{
                    front++;
                }
            }

        }
    }
    return 0;
}