/*
    이번에 삽입정렬로 구현한다.
    첫 구간에서 가장 작은 것을 찾아 맨 앞로 옯기는 식이다.
    버블정렬은 옆의 것과 비교하지만 삽입정렬은 min_idx를 만들어서 비교한다.
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[1001], n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 삽입정렬
    for (int i = 0; i < n; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}