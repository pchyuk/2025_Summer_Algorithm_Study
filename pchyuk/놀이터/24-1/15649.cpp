#include <iostream>
#define MAX 9
using namespace std;
int arr[MAX]; // 0으로 초기화
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
        if(!selected[i]){ // 선택되지 않았다면 - 가지치기(백트래킹)
            selected[i] = true; // 상태 변화
            arr[count] = i+1; // 배열에 값을 집어넣는다.
            dfs(count + 1); // 재귀 호출
            selected[i] = false; // 다음 경우의 수를 위해 상태 복구
        }
    }
    
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> r;
    
    dfs(0);
    return 0;
}