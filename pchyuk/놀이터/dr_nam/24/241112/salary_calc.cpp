// salary_calc.cpp

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    cout << "*** 근무 시간 계산기 ***\n\n";

    cout << "이번 달 근무 시간을 입력해 주세요.\n";
    cout << "[시간 분] 형식으로 작성해 주시고 (예: 3시간 40분 근무 => 3 40 입력)\n";
    cout << "다 입력하셨다면 [0 0]을 입력해 주세요.\n\n";

    int h, m;
    int sum_h = 0, sum_m = 0;
    
    while(1){
        cout << "근무 시간 [시간 분]: ";
        cin >> h >> m;
        if(h==0) break;
        sum_h += h;
        sum_m += m;
    }

    while(sum_m >= 60){
        sum_m -= 60;
        sum_h++;
    }

    cout << "\n이번 달 총 근무 시간은 " << sum_h << "시간 " << sum_m << "분 입니다.\n";
    cout << "이번 달도 고생 많으셨습니다.\n\n";
    
    return 0;
}