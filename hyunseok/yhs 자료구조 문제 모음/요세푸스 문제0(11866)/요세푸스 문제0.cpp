#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    int yosep = 0;
    int circulation;
    vector<int> result;
    vector<int> circle;
    cin>>N;
    cin>>K;
    for(int i = 0; i<N; i++){
        circle.push_back(i+1);
    }
    while(circle.empty() != true){
        yosep = (yosep + K-1)%circle.size();
        result.push_back(circle[yosep]);
        circle.erase(circle.begin()+yosep);
    }
    cout<<"<";
    for(int i = 0; i<result.size(); i++){
        if(i == result.size()-1){
            cout<<result[i];
            break;
        }
        cout<<result[i]<<", ";
    }
    cout<<">";
    return 0;
}