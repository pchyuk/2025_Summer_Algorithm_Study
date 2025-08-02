#include <iostream>
using namespace std;
int com[1001][1001];
long long line[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> com[i][j];
            line[i] += com[i][j];
        }
    }

    for(int i=n-1; i>=0; i--){
        line[i] += line[i+1];
        //cout << i << "층 : " << line[i] << "\n";
    }

    if(line[0] == 0){
        cout << "0\n";
        return 0;
    }

    int start = 0, end = n-1;
    int mid = (start + end) / 2;
    while(start < end){
        
    }
    return 0;
}