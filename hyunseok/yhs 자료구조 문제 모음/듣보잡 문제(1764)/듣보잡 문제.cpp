#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int check = 0;
    string tmp;
    vector<string> no_s_name;
    vector<string> no_r_name;
    vector<string> result;
    int left, right, middle;
    cin>>N;
    cin>>M;
    for(int i = 0; i<N; i++){
        cin>>tmp;
        no_s_name.push_back(tmp);
    }
    for(int i = 0; i<M; i++){
        cin>>tmp;
        no_r_name.push_back(tmp);
    }
    sort(no_r_name.begin(), no_r_name.end());
    for(int i = 0; i<N; i++){
        left = 0, right = M-1;
        while(left<=right){
            middle = (left+right)/2;
            if(no_r_name[middle] == no_s_name[i]){
                result.push_back(no_s_name[i]);
                check++;
                break;
            }
            else if(no_r_name[middle] < no_s_name[i]){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
    }
    cout<<check<<"\n";
    sort(result.begin(), result.end());
    if(check != 0){
        for(int i = 0; i<check; i++){
            cout<<result[i]<<"\n";
        }
    }
    return 0;
}