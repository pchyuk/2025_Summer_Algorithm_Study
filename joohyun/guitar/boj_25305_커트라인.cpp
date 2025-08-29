/*
    https://www.acmicpc.net/problem/25305
    벡터로 입력받고, 오름차순으로 정렬하고, 뒤에서 k번째를 출력하면 된다.
    학습을 위해 병합정렬로도 풀어본다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp(1000);

void merge(vector<int>& score, int p, int middle, int q) {
    int i = p, j = middle + 1, k = p;
    while (i <= middle && j <= q) {
        if (score[i] <= score[j]) temp[k++] = score[i++];
        else temp[k++] = score[j++];
    }

    while (i <= middle) temp[k++] = score[i++];
    while (j <= q) temp[k++] = score[j++];

    for (int i = p; i <= q; i++) score[i] = temp[i];
}

void merge_sort(vector<int>& score, int p, int q) {
    if (p == q) return;

    int middle = (p + q) / 2;
    merge_sort(score, p, middle);
    merge_sort(score, middle + 1, q);
    merge(score, p, middle, q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> score(n);
    for (int i = 0; i < n; i++) cin >> score[i];

    // sort(score.begin(), score.end());
    merge_sort(score, 0, n - 1);

    cout << score[n - k];
    return 0;
}