/*
1. 회의를 종료 시간을 기준으로 오름차순으로 정렬
1-1. 종료 시간이 같다면, 시작 시간을 기준으로 오름차순으로 정렬
종료 시간이 빠른 회의를 먼저 선택해야 뒤에 더 많은 회의를 배정할 수 있는 기회가 생기기 때문
2. 가장 빨리 끝나는 회의를 먼저 선택
2-1. 다음 회의를 선택할 때, 이전에 선택한 회의의 종료 시간보다 시작 시간이 같거나 늦은 회의 중 가장 빨리 끝나는 회의를 선택
3. 이 과정을 더이상 선택할 수 있는 회의가 없을 때가지 반복
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

// 회의 정보를 저장할 구조체
struct Meeting
{
    int start;
    int end;
};

// 종료 시간을 기준으로 오름차순 정렬, 종료 시간이 같으면 시작 시간을 기준으로 오름차순 정렬
bool compareTime(const Meeting& a, const Meeting& b)
{
    if(a.end == b.end)
    {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 변수 입력
    int N;
    cin >> N;
    vector<Meeting> meetings(N);
    for(int i = 0; i < N; i++)
    {
        cin >> meetings[i].start >> meetings[i].end;
    }
    
    // 회의 정렬
    sort(meetings.begin(), meetings.end(), compareTime);

    int meeting_count = 0; // 배정된 회의의 수
    int last_end_time = 0; // 마지막으로 선택된 회의의 종료 시간

    // 정렬된 회의들을 순회하며 회의 배정
    for(int i = 0; i < N; i++)
    {
        // 현재 회의의 시작 시간이 마지막 회의의 종료 시간보다 같거나 늦으면:
        if(meetings[i].start >= last_end_time)
        {
            meeting_count++; // 회의 배정
            last_end_time = meetings[i].end; // 마지막 회의 종료 시간 갱신
        }
    }
    cout << meeting_count << endl;

    return 0;
}