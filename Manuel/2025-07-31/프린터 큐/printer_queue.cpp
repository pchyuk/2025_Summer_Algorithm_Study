#include <iostream>
#include <queue>
#include <vector>
#include <utility> // pair를 사용하기 위한 헤더 (중요도, 인덱스 쌍을 저장)
#include <algorithm>

#define endl "\n"

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;

    // 각 문서에 (중요도, 원래 인덱스) 쌍이 필요하므로 pair 사용
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++)
    {
        int priority; // 현재 문서의 중요도
        cin >> priority;
        q.push({priority, i});
    }
    
    int print_order_count = 0; // 인쇄된 문서의 순서를 세는 변수

    while(!q.empty()) // 큐가 비어 있지 않을 때까지 문서 인쇄 과정 구현
    {
        // 큐의 가장 앞의 문서 꺼내기
        pair<int, int> current_doc = q.front();
        q.pop();
        int current_priority = current_doc.first; // 현재 문서의 중요도
        int current_original_index = current_doc.second;
        
        // 큐에 중요도가 현재 문서보다 높은 문서가 있는지 확인
        bool higher_yes = false;
        // C++의 queue는 직접적으로 순회할 수 없음 (이거 때문에 생각보다 머리 아팠음)
        // 모든 요소를 꺼냈다가 다시 넣는 방법으로 대체 (Thanks to you, Google...)
        int q_size = q.size();
        for(int i = 0; i < q_size; i++)
        {
            pair<int, int> temp = q.front(); // 큐의 맨 앞 문서를 지정
            q.pop(); // 꺼냄

            if(temp.first > current_priority) // 더 높은 중요도의 문서를 찾으면 플래그 설정
            {
                higher_yes = true;
            }
            q.push(temp); // 아니면 루프를 돌면서 모든 문서를 다시 큐에 넣음
        }

        if(higher_yes) // 더 높은 중요도의 문서가 있었다면, 현재 문서를 큐의 맨 뒷자리로 넣음
        {
            q.push(current_doc);
        }
        else // 현재 문서가 중요도가 제일 높았다면
        {
            print_order_count++; // 인쇄 순서를 1 증가
            // 만약 인쇄된 문서가 우리가 찾던 문서라면
            if(current_original_index == M)
            {
                cout << print_order_count << endl;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // 테스트 케이스의 개수
    cin >> T;

    for(int i = 0; i < T; i++) // T개의 테스트 케이스를 순서대로 처리
    {
        solve();
    }

    return 0;
}