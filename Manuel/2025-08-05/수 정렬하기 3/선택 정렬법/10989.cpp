#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

void selection_sort(vector<int>& arr)
{
    int n = arr.size();

    // 정렬되지 않은 부분 배열의 시작 인덱스
    for(int i = 0; i < n - 1; i++)
    {
        // 가장 작은 원소의 인덱스
        int min_index = i;
        // 정렬되지 않은 부분 배열에서 최솟값 찾기
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
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

    selection_sort(numbers);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }

    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}