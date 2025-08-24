#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int max = 0, min = v[0], uphill = 0;
    for(int i=1; i<n; i++){
        if(v[i] > v[i-1]){
            max = v[i];
            // cout << i << " : max = " << max << "\n";
            if(uphill < max - min){
                uphill = max - min;
                // cout << i << " : uphill = " << uphill << "\n";
            }
        }
        else {
            min = v[i];
            // cout << i << " : min = " << min << "\n";
        }
    }
    
    if(min != v[n-1] && uphill < max - min) uphill = max - min;
    cout << uphill << "\n";
    return 0;
}