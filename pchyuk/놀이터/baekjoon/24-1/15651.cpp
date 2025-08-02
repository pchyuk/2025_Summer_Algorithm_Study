#include <iostream>
#define MAX 9
using namespace std;
int arr[MAX];

int n, r;

void print(){
    for(int i=0; i<r; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void dfs(int index, int count){
    if(count == r){
        print();
        return;
    }
    for(int i=index; i<=n; i++){
        arr[count] = i;
        dfs(i, count + 1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> r;
    
    dfs(1, 0);
    return 0;
}