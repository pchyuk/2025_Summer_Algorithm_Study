#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

void bubble_sort(vector<int>& arr)
{
    int n = arr.size();
    bool swapped;

    // 배열의 끝에서부터 정렬된 원소가 쌓여가기 때문에 정렬 범위는 n-1부터 1까지 줄어듦
    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;
        // 인접 원소를 비교하고 교환함
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // 한 번 순회하면서 교환이 한 번도 일어나지 않았다면 배열은 정렬되었다는 의미
        if(!swapped)
        {
            break;
        }
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

    bubble_sort(numbers);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }

    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}