#include <iostream>
using namespace std;
void move(int n){
    int count[21];
    count[1] = 1;
    for(int i=2; i<21; i++){
        count[i] = 2*count[i-1] + 1;
    }
    cout << count[n] << "\n";
}

void hanoi(int n, int from, int tmp, int to){
    if(n==1) cout << from << " " << to << "\n";
    else {
        hanoi(n-1, from, to, tmp);
        cout << from << " " << to << "\n";
        hanoi(n-1, tmp, from, to);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    move(n);
    hanoi(n, 1, 2, 3);
    return 0; 
}