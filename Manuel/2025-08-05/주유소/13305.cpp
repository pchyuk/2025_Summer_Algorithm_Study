#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 도시의 개수 입력받음
    vector<long long> road_len(N - 1);
    for(int i = 0; i < N - 1; i++)
    {
        cin >> road_len[i]; // 도로의 거리 입력받음
    }
    vector<long long> prices(N);
    for(int i = 0; i < N; i++)
    {
        cin >> prices[i]; // 주유소의 가격 입력받음
    }

    long long total_cost = 0;
    // 현재까지 방문한 도시들 중 가장 저렴한 주유 가격을 저장
    // 첫 번째 도시에서는 무조건 주유하므로 prices[0]으로 초기화함
    long long current_min_price = prices[0];

    // 첫 번째 도시의 주유 가격과 현재까지의 최소 가격을 비교하여 갱신함
    // 마지막 도시는 도착지이므로 주유할 필요 없음
    for(int i = 0; i < N - 1; i++)
    {
        // 현재 도시의 주유 가격과 현재까지의 최소 가격을 비교하여 갱신함
        current_min_price = min(current_min_price, prices[i]);
        // 갱신된 최소 가격으로 현재 도로 길이만큼 주유하여 총 비용에 추가
        total_cost += current_min_price * road_len[i];
    }

    cout << total_cost << endl;

    return 0;
}