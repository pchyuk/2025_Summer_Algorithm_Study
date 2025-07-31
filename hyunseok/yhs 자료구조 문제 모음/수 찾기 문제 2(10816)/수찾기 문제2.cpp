#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, tmp;
    unordered_map<int, int> nums;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>tmp;
        nums[tmp]++;
       
    }
    cin>>M;
    for(int i = 0; i<M; i++){
        cin>>tmp;
        cout<<nums[tmp]<<" ";
    }

    return 0;
}