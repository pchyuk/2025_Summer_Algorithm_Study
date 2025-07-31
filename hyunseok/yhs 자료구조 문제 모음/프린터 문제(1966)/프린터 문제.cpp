#include <iostream>
using namespace std;

//ť ���
int queue[10000];
int front = -1, rear = -1;

int main(){
    int N, M, T;
    //check�� ���� �߿䵵 ũ�� �Ǻ�
    //order�� ��� ����
    int check, order = 0;
    cin>>T;
    for(int i = 0; i<T; i++){
        front = -1, rear= -1;
        order = 0;
        cin>>N;
        cin>>M;
        //���� �߿䵵 �Է�
        //�������� ����ϰ��� �ϴ� ������ �����ϱ� ���� �߿䵵�� 9����
        for(int j = 0; j<N; j++){
            cin>>queue[++rear];
            if(j == M){
                queue[rear] += 9;
            }
        }
        //���� ��� ���� �Ǻ�
        while(front != rear){
            check = 0;
            //���� �߿䵵 ũ�� �Ǻ�
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