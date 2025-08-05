#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

// 분할 함수
int partition(vector<int>& arr, int left, int right)
{
    // 피봇을 배열의 가장 오른쪽 원소로 선택
    int pivot = arr[right];
    // i는 피봇보다 작은 원소들의 경게선
    int i = left - 1;

    // left부터 right - 1까지 순회하며 피봇과 비교함
    for(int j = left; j < right; j++)
    {
        // 현재 원소가 피봇보다 작거나 같으면:
        if(arr[j] <= pivot)
        {
            // i 증가, i와 j 교환
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // 피봇을 i + 1로 이동시켜 정렬된 위치에 배치
    swap(arr[i + 1], arr[right]);
    // 피봇의 위치 반환
    return i + 1;
}

// 재귀를 활용하여 배열을 정렬하는 퀵 정렬 함수
void quick_sort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        // 분할 수행, 피봇 위치 반환
        int pivot_index = partition(arr, left, right);
        
        // 피봇을 기준으로 왼쪽과 오른쪽 각각 배열 정렬
        quick_sort(arr, left, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, right);
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

    quick_sort(numbers, 0, N - 1);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }

    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}