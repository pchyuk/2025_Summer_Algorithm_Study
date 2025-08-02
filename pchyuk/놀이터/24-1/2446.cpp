#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout << " ";
        }
        for(int k=0; k<2*(n-i)-1; k++){
            cout << "*";
        }
        cout << "\n";
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-2; j++){
            cout << " ";
        }
        for(int k=0; k<2*(i+1)+1; k++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}