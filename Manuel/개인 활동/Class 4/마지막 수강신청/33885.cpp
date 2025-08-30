#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m; // 과목 수, 최소 학점

    // 각 과목의 정보 저장
    vector<int> credits(n); // 학점
    vector<vector<pair<string, int>>> schedules(n); // 각 과목의 시간표

    // 1단계: 입력 받기
    for(int i = 0; i < n; i++)
    {
        int lecture_count;
        cin >> credits[i] >> lecture_count; // 학점, 강의 횟수

        // 강의 시간 입력받기
        for(int j = 0; j < lecture_count; j++)
        {
            string day;
            int time;
            cin >> day >> time; // 요일, 시간
            schedules[i].push_back({day, time});
        }
    }

    // 2단계: 모든 조합 확인하기 (비트마스킹)
    // 1부터 2^(n - 1)까지 모든 경우의 수 확인
    
    for(int mask = 1; mask < (1 << n); mask++)
    {
        // 현재 조합에서 선택한 과목들 찾기
        vector<int> selected_subjects;
        int total_credits = 0;

        for(int i = 0; i < n; i++)
        {
            // i번째 비트가 1이면 i번째 과목 선택됨
            if(mask & (1 << i))
            {
                selected_subjects.push_back(i);
                total_credits += credits[i];
            }
        }
        // 학점이 부족하면 다음 조합으로
        if(total_credits < m)
        {
            continue;
        }

        // 3단계: 시간표 충돌 확인
        set<pair<string, int>> used_times; // 사용된 (요일, 시간)
        bool conflict = false; // 충돌 여부

        // 선택된 모든 과목의 시간표 확인
        for(int subject_idx : selected_subjects)
        {
            // 이 과목의 모든 강의 시간 확인
            for(auto& lecture : schedules[subject_idx])
            {
                string day = lecture.first;
                int time = lecture.second;

                // 이미 사용된 시간이면 충돌
                if(used_times.count({day, time}))
                {
                    conflict = true;
                    break;
                }
                used_times.insert({day, time});
            }
            if(conflict)
                break; // 충돌 발생 시 중단
        }
        // 4단계: 조건을 만족하면 성공
        if(!conflict)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    // 모든 조합을 찾아봤지만 조건을 만족하는 것이 없음
    cout << "NO" << endl;
    return 0;
}