#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // cout << "\n";

    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}