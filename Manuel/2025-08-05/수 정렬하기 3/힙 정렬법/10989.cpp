#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

// 최대 힙 속성을 유지시키는 함수
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i; // 가장 큰 값을 루트로 가정함
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // 왼쪽 자식이 현재 루트보다 크면:
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    // 오른쪽 자식이 현재 가장 큰 값보다 크면
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
}

// 힙 정렬 함수
void heap_sort(vector<int>& arr)
{
    int n = arr.size();

    // 초대 힙으로 변환하기:
    // 마지막 부모 노드부터 루트까지 순회
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    // 정렬하기
    for(int i = n - 1; i > 0; i--)
    {
        // 루트(최대값)와 마지막 원소 교환
        swap(arr[0], arr[i]);
        // 힙의 크기를 줄이고 다시 heapify 호출
        heapify(arr, i, 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    auto start_time = chrono::high_resolution_clock::now();

    heap_sort(numbers);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }

    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}