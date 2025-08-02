// salary_calc.cpp

#include <iostream>
#define WAGE 10500
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    cout << "*** 근무 시간 & 월급 계산기 ***\n\n";

    cout << "이번 달 근무 시간을 입력해 주세요.\n";
    cout << "[시간 분] 형식으로 작성해 주시고 (예: 3시간 40분 근무 => 3 40 입력)\n";
    cout << "다 입력하셨다면 [0 0]을 입력해 주세요.\n\n";

    int h, m, i = 0;
    int sum_h = 0, sum_m = 0;
    
    while(1){
        cout << ++i << "회차 근무 시간 [시간 분]: ";
        cin >> h >> m;
        if(h==0) break;
        sum_h += h;
        sum_m += m;
    }

    while(sum_m >= 60){
        sum_m -= 60;
        sum_h++;
    }

    cout << "\n이번 달 총 근무 횟수는 " << i-1 << "회 입니다.\n";
    cout << "이번 달 총 근무 시간은 " << sum_h << "시간 " << sum_m << "분 입니다.\n\n";

    cout << "시급 " << WAGE << " 원으로 계산했을 때,\n";
    cout << "이번 달 예상 급여는 " << sum_h * WAGE + sum_m * WAGE / 60 << "원 입니다.\n\n";

    if(sum_m >= 30) sum_h++;
    cout << "인센티브(약 5%)를 포함한 예상 급여는 " << sum_h * 1.05 * WAGE << "원 입니다.\n\n";
    
    cout << "이번 달도 고생 많으셨습니다!\n\n";
    
    return 0;
}