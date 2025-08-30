#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define endl "\n"

using namespace std;

unordered_map<int, int> memo;

int calculateGrundy(int n)
{
    /*
    님 게임 나누기에서 가능한 움직임:
    1. 제거: n -> k (k = 0, 1, ... , n - 1)
    2. 분할: n -> (a, b), 이때 (a + b = n, a >= 1, b >= 1)
    */

    if(memo.find(n) != memo.end())
    {
        return memo[n];
    }

    if(n == 0)
    {
        memo[n] = 0;
        return 0;
    }

    // 가능한 다음 상태들의 그런디 집합
    unordered_set<int> nextStates;

    // 1. 제거: k개 돌을 남김 (0 <= k < n)
    for(int k = 0; k < n; k++)
    {
        nextStates.insert(calculateGrundy(k));
    }
    // 2. 분할: n = a + b (a >= 1, b >= 1)
    for(int a = 1; a < n; a++)
    {
        int b = n - a;
        if(b >= 1)
        {
            // 두 더미의 그런디 수를 XOR 연산함
            int grundyA = calculateGrundy(a);
            int grundyB = calculateGrundy(b);
            nextStates.insert(grundyA ^ grundyB);
        }
    }

    // MEX 계산
    int mex = 0;
    while(nextStates.find(mex) != nextStates.end())
    {
        mex++;
    }

    memo[n] = mex;
    return mex;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> stones(n);
    int nimSum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> stones[i];
        nimSum ^= calculateGrundy(stones[i]);
    }

    if(nimSum != 0)
    {
        cout << "koosaga" << endl;
    }
    else
    {
        cout << "cubelover" << endl;
    }

    return 0;
}