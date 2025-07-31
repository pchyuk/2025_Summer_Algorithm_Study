#include <iostream>
using namespace std;

int main(){
    int top = -1;
    int k;
    int check;
    int sum = 0;
    int arr[100000] = {0};
    cin>>k;
    for(int i = 0; i<k; i++){
        cin>>check;
        if(check == 0){
            arr[top--] = 0;
        }
        else{
            arr[++top] = check;
        }
    }
    for(int i = 0; i<=top; i++){
        sum+=arr[i];
    }
    cout<<sum;
    return 0;
}