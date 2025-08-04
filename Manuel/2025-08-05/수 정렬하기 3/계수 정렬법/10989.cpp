#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    // 입력 값 저장을 위한 임시 벡터
    vector<int> input_numbers(N);
    for(int i = 0; i < N; i++)
    {
        cin >> input_numbers[i];
    }

    auto start_time = chrono::high_resolution_clock::now();
    
    // 수의 최대 범위는 10000
    vector<int> count_array(10001, 0);
    // 입력 값의 출현 횟수를 셈
    for(int num : input_numbers)
    {
        count_array[num]++;
    }
    // count_array를 순회하며 정렬된 결과 출력
    for(int i = 1; i <= 10000; i++)
    {
        if(count_array[i] > 0)
        {
            for(int j = 0; j < count_array[i]; j++)
            {
                cout << i << endl;
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double, ::milli> duration = end_time - start_time;
    cout << "\n실행 시간: " << fixed << setprecision(6) << duration.count() << "ms" << endl;
    return 0;
}