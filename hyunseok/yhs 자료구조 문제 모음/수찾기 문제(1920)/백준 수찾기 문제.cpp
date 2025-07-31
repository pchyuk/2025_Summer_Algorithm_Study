#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int search_num[100000];

int main(){
    int repeat1;
    int repeat2;
    int left, right, middle = -1;
    int check = 0;
    cin>>repeat1;
    for(int i = 0; i<repeat1; i++){
        cin>>arr[i];
    }
    sort(arr, arr+repeat1);
    cin>>repeat2;
    for(int i = 0; i<repeat2; i++){
        cin>>search_num[i];
    }
    for(int i = 0; i<repeat2; i++){
        left = 0, right = repeat1-1, check = 0;
        middle = -1;
        while(left <= right){
            middle = (left+right)/2;
            if(arr[middle] == search_num[i]){
                check = 1;
                break;
            }
            else if(search_num[i]<arr[middle]){
                check = 0;
                right = middle - 1;
            }
            else{
                check = 0;
                left = middle + 1;
            }
        }
        cout<<check<<"\n";
    }
    return 0;
}