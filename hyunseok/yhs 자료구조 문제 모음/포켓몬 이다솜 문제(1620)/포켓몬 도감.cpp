#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, num;
    string tmp;
    vector<string> s;
    map<string, int> m;
    cin>>N;
    cin>>M;
    for(int i = 0; i<N; i++){
        cin>>tmp;
        s.push_back(tmp);
        m.insert(make_pair(s[i], i+1));
    }

    for(int i = 0; i<M; i++){
        cin>>tmp;
        if(tmp[0] >= '0' && tmp[0] <= '9'){
            num = stoi(tmp);
            cout<<s[num-1]<<"\n";
        }
        else{
            cout<<m[tmp]<<"\n";
        }
    }
    return 0;
}