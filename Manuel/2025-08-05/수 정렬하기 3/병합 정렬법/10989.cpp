#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

// 임시 배열
vector<int> temp;

// 두 개의 정렬된 부분 배열을 병합하는 함수
void merge(vector<int>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    // 두 부분의 배열을 비교하여 더 작은 요소를 temp 배열에 저장
    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    // 남은 왼쪽 부분 배열의 요소들을 temp에 복사함
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    // 남은 오른쪽 부분 배열의 요소들을 temp에 복사함
    while(j <= right)
    {
        temp[k++] = arr[j++];
    }
    // 정렬된 temp 배열의 내용을 원래 배열로 복사
    for(int l = left; l <=right; l++)
    {
        arr[l] = temp[l];
    }
}

// 재귀를 이용하여 배열을 분할하고 병합해주는 함수
void merge_sort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        // 왼쪽 부분 배열 정렬
        merge_sort(arr, left, mid);
        // 오른쪽 부분 배열 정렬
        merge_sort(arr, mid + 1, right);
        // 정렬된 두 부분의 배열을 병합
        merge(arr, left, mid, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // int 벡터 안에 값을 입력 후 저장
    vector<int> numbers(N);
    for(int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    
    // 임시 배열 크기 초기화
    temp.resize(N);

    auto start_time = chrono::high_resolution_clock::now();

    // 병합 정렬 실행
    merge_sort(numbers, 0, N - 1);

    auto end_time = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        cout << numbers[i] << endl;
    }

    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;

    return 0;
}