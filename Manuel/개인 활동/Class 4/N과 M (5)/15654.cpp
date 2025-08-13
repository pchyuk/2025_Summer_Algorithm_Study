/*
백트래킹 알고리즘: 해를 찾는 과정에서 해가 될 수 없는 경로를 일찍 포기하여 효율성을 높이는 방법
원리:
1. 재귀적 접근
    문제를 작은 하위 문제로 나누고 재귀적으로 해결
2. 후보군 생성
    각 단계에서 해가 될 수 있는 여러 후보 생성
3. 유망성 검사
    현재까지의 선택이 해가 될 가능성이 있는지 확인. 가능성이 없다면 이전 단계로 돌아감(중요)
4. 복원
    이전 단계로 돌아가서 다른 후보를 탐색하기 위해 현재 단계에서 만든 변경사항을 되돌림

적용:
리스트의 길이가 M과 같지 않은 경우:
    - 1부터 N까지 숫자를 하나씩 선택
    - 이전에 선택한 적이 없는 숫자라면 현재 리스트에 추가, 다음 단계를 재귀적으로 탐색
    - 재귀 탐색을 끝내면, 다음 후보를 탐색하기 위해 현재 리스트에서 방금 추가한 숫자를 제거
리스트의 길이가 M과 같을 경우:
    = 해를 찾았으므로 리스트 출력, 재귀 탐색 종료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M;
vector<int> numbers;
vector<int> current_list;
vector<bool> visited;

// 백트래킹 함수
void dfs()
{
    // 기저 조건: M개의 숫자를 모두 골랐다면
    if(current_list.size() == M)
    {
        // 현재 리스트 출력
        for(int i = 0; i < M; i++)
        {
            cout << current_list[i] << " ";
        }
        cout << endl;
        return;
    }

    // 정렬된 numbers 리스트를 순회하며 탐색
    for(int i = 0; i < N; i++)
    {
        // 현재 숫자를 아직 방문하지 않았다면
        if(!visited[i])
        {
            visited[i] = true;
            current_list.push_back(numbers[i]); // 현재 숫자를 리스트에 추가
            dfs(); // 재귀 호출
            current_list.pop_back(); // 백트래킹: 추가한 숫자 제거
            visited[i] = false; // 방문 상태 되돌리기
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    numbers.resize(N);
    visited.resize(N, false);
    for(int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());
    dfs();

    return 0;
}