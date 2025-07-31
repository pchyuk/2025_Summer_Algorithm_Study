#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    int tmp;
    priority_queue<int> max_heap;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>tmp;
        if(tmp == 0){
            if(max_heap.empty() == 1){
                cout<<"0\n";
            }
            else{
                cout<<max_heap.top()<<"\n";
                max_heap.pop();
            }
        }
        else{
            max_heap.push(tmp);
        }
    }
    return 0;
}