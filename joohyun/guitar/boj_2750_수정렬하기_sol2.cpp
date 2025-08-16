/*
    학습용으로 버블정렬로 구현
    버블정렬은 2중 for문으로 뒤에서부터 차례로 정렬시킨다.
    첫 번째 for문에서 정렬할 구간을 정하고
    두 번째 for문에서 큰 것을 계속 뒤로 옮긴다.
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[1001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    
    return 0;
}