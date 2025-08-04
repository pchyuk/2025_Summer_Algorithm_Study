#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

// 기수 정렬에 사용될 계수 정렬 함수
void counting_sort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // 각 자릿수에 해당하는 숫자의 개수를 셈
    for(int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    // count 배열을 누적 합으로 변경
    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    // 안정적으로 배열을 정렬하기 위해서 뒤에서부터 순회하면서 output 배열에 저장
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // output 배열의 내용을 원래 배열로 복사
    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// 기수 정렬 함수
void radix_sort(vector<int>& arr)
{
    // 가장 큰 값을 찾아 자릿수 결정
    int max_val = *max_element(arr.begin(), arr.end());

    // 1의 자리부터 시작하여 자릿수별로 계수 정렬 실행
    for(int exp = 1; max_val / exp > 0; exp *= 10)
    {
        counting_sort(arr, exp);
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

    radix_sort(numbers);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }
    
    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}