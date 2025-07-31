#include <iostream>
#include <map>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    int tmp;
    map<int, int> arr;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>tmp;
        arr.insert(make_pair(tmp, 1));
    }
    cin>>M;
    for(int i = 0; i<M; i++){
        cin>>tmp;
        if(arr.count(tmp) == 0){
            cout<<"0 ";
        }
        else{
            cout<<arr[tmp]<<" ";
        }
    }
    return 0;
}