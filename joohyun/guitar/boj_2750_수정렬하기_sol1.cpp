/* 만약 대회라면 sort()를 사용하는 것이 가장 합리적이다. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int x : arr) {
        cout << x << '\n';
    }

    return 0;
}