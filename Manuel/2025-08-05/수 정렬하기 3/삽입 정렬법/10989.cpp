#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

void insertion_sort(vector<int>& arr)
{
    int n = arr.size();
    // 두 번째 원소부터 리스트의 끝까지 순회
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // key 값보다 큰 원소들을 뒤로 한 칸씩 이동
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        // key 값을 올바른 위치에 삽입
        arr[j + 1] = key;
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

    insertion_sort(numbers);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }

    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}