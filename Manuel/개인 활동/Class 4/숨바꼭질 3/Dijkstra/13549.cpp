/*
우선 0-1 BFS 설명을 먼저 보고 오는 것을 추천.

다익스트라 알고리즘 순서:
1. 우선순위 큐를 사용, 소요 시간이 가장 짧은 노드부터 탐색한다.
2. time 배열에 각 위치에 도달하는 데 걸리는 최소 시간을 저장한다.
3. 시작 위치의 시간을 0으로 설정하고 우선순위 큐에 넣는다.
4. 우선순위 큐에서 가장 시간이 짧은 노드를 꺼내고, 인접한 노드(X - 1, X + 1, 2 * X)의 시간을 갱신한다.
5. 만약 인접한 노드에 더 짧은 시간으로 도달할 수 있다면, time 배열을 업데이트하고 큐에 추가한다.

다익스트라 알고리즘의 장단점:
어떤 간선 가중치 조합이든(0, 1, 2, ...) 작동한다는 장점이 있지만, 음수 가중치에는 잘 작동하지 않는다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define endl "\n"

using namespace std;

const int MAX = 100001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if(n >= k)
    {
        cout << n - k << endl;
        return 0;
    }

    // 각 위치까지의 최단 시간을 저장할 배열
    vector<int> time(MAX, numeric_limits<int>::max());
    // 우선순위 큐: {시간, 위치} 쌍을 저장하며 시간이 작은 순서대로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // 시작 위치 n의 시간을 0으로 초기화하고 큐에 추가
    time[n] = 0;
    pq.push({0, n});

    while(!pq.empty())
    {
        int current_time = pq.top().first;
        int current_pos = pq.top().second;
        pq.pop();

        // 현재 꺼낸 시간이 이미 기록된 시간보다 크다면 더이상 탐색할 필요가 없음
        if(current_time > time[current_pos])
        {
            continue;
        }
        // 동생의 위치에 도달했다면 탐색 종료
        if(current_pos == k)
        {
            cout << current_time << endl;
            return 0;
        }

        // 순간이동 (2 * X): 가중치 0
        int teleport = current_pos * 2;
        if(teleport < MAX && time[teleport] > current_time)
        {
            time[teleport] = current_time;
            pq.push({current_time, teleport});
        }

        // 걷기 (X - 1): 가중치 1
        int walk_back = current_pos - 1;
        // 기존 최단 시간(time[walk_back])보다 현재 경로를 통해 도달하는 시간(current_time + 1)을 비교
        if(walk_back >= 0 && time[walk_back] > current_time + 1)
        {
            time[walk_back] = current_time + 1; // 한 칸을 걷는 데 1초가 걸리기 때문에 1을 더한 값을 갱신
            pq.push({current_time + 1, walk_back});
        }

        // 걷기 (X + 1): 가중치 1
        int walk_forward = current_pos + 1;
        if(walk_forward < MAX && time[walk_forward] > current_time + 1)
        {
            time[walk_forward] = current_time + 1;
            pq.push({current_time + 1, walk_forward});
        }
    }
    return 0;
}