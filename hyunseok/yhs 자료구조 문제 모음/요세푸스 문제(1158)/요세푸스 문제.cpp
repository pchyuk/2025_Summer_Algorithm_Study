#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    int yosep = 0;
    vector<int> circle;
    cin>>N;
    cin>>K;
    for(int i = 0; i<N; i++){
        circle.push_back(i+1);
    }
    cout<<"<";
    while(circle.empty() != true){
        yosep = (yosep + K-1)%circle.size();
        if(circle.size()>1){        
            cout<<circle[yosep]<<", ";
        }
        else{
            cout<<circle[yosep];
        }
        circle.erase(circle.begin()+yosep);
    }
    return 0;
}