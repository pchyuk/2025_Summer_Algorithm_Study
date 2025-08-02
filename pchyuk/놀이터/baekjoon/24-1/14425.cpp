#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> search(n);
    for(int i=0; i<n; i++){
        cin >> search[i];
    }

    sort(search.begin(), search.end());
    string str;
    int count = 0;
    for(int i=0; i<m; i++){
        cin >> str;
        if(binary_search(search.begin(), search.end(), str)) count++;
    }

    cout << count << "\n";
    return 0;
}