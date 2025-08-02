#include <iostream>
using namespace std;

int euclidian(int a, int b){
    int r = a;
    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        cout << a*b / euclidian(a,b) << "\n";
    }
    return 0;
}