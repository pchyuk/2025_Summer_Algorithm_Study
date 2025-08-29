/*
    https://www.acmicpc.net/problem/24060
*/
#include <iostream>
using namespace std;

int a[500000], tmp[500000];
int k, cnt, num; // 배열a와 a에 저장된 횟수를 카운트할 cnt

// 병합정렬
void merge(int a[], int m, int middle, int n) {
    int i = m, j = middle + 1, t = m;
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }

    while (i <= middle) tmp[t++] = a[i++];
    while (j <= n) tmp[t++] = a[j++];

    for (int i = m; i <= n; i++) {
        a[i] = tmp[i];
        cnt++;
        if (cnt == k) {
            num = a[i];
            return;
        }
    }
    
}

void mergeSort(int a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 병합정렬을 시행하면서 k에 해당되는 숫자를 찾기
    mergeSort(a, 0, n - 1);
    
    // 수 출력
    cout << (num != 0 ? num : -1);

    return 0;
}