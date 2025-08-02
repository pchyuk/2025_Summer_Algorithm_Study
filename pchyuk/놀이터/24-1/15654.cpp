#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;
int arr[MAX];
int input[MAX];
bool selected[MAX]; // false로 초기화

int n, r;

void print(){
    for(int i=0; i<r; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void dfs(int count){
    if(count == r){
        print();
        return;
    }
    for(int i=0; i<n; i++){
        if(!selected[i]){
            selected[i] = true;
            arr[count] = input[i];
            dfs(count + 1);
            selected[i] = false;
        }
    }
    
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> r;
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    sort(input, input + n);
    
    dfs(0);
    return 0;
}