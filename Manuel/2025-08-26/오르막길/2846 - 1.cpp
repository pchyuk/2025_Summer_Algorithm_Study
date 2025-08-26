#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev, current;
    cin >> prev; // 첫 번째 높이

    int max_uphill = 0; // 가장 큰 오르막길 높이 차이
    int current_uphill = 0; // 현재 오르막길 높이 차이

    // 두 번째 높이부터 비교 시작
    for(int i = 1; i < n; i++)
    {
        cin >> current;
        if(prev < current) // 오르막길인 경우
        {
            current_uphill += current - prev;
            max_uphill = max(max_uphill, current_uphill);
        }
        else
        {
            current_uphill = 0;
        }
        prev = current; // 다음 비교를 위해 현재 값을 이전의 값으로 설정
    }
    cout << max_uphill << endl;
    return 0;
}