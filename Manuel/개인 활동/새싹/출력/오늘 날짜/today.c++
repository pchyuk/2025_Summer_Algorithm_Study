#include <iostream>
#include <ctime>
#include <iomanip> // 출력 포맷 조절을 위한 헤더 (std::put_time 사용)

using namespace std;

int main()
{
    // 현재 UTC 시간을 가져옴
    time_t now_utc_time = time(nullptr);
    // UTC 시간을 tm 구조체로 변환
    struct tm* tm_utc = gmtime(&now_utc_time);
    // 한국 시간(KST)에 맞춤
    tm_utc->tm_hour += 9;
    // 시간이 24시간을 넘어가거나 음수가 될 경우 날짜가 올바르게 갱신되도록 함
    time_t korea_time_t = mktime(tm_utc);
    //정규화된 time_t 값을 다시 tm 구조체로 변환
    struct tm* tm_korea = localtime(&korea_time_t);
    cout << put_time(tm_korea, "%Y-%m-%d") << endl;
}