#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    int tmp;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>tmp;
        if(tmp == 0){
            if(minHeap.empty() == 1){
                cout<<"0\n";
            }
            else{
                cout<<minHeap.top()<<"\n";
                minHeap.pop();
            }
        }
        else{
            minHeap.push(tmp);
        }
    }
    return 0;
}