// 술 먹고 쓴 코드. 내가 애인한테도 이렇게 정성스럽게 글 안 써주는데

#include <iostream>
#include <vector>
#include <chrono>

#define endl "\n"

using namespace std;

struct Count
{
    int zero;
    int one;
};

vector<Count> dp(41);

// dp 테이블을 미리 채우기
void preCompute()
{
    dp[0] = {1, 0};
    dp[1] = {0, 1};

    // 2부터 40까지 테이블 채우기
    for(int i = 2; i <= 40; i++)
    {
        dp[i].zero = dp[i - 1].zero + dp[i - 2].zero;
        dp[i].one = dp[i - 1].one + dp[i - 2].one;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    preCompute();

    for(int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        auto start = chrono::high_resolution_clock::now();

        Count result = dp[N];

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;

        cout << result.zero << " " << result.one << endl;
        cout << "실행 시간: " << duration.count() << "ms" << endl;
    }

    return 0;
}