#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> stones(n);
    int nim_sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> stones[i];
        nim_sum ^= stones[i];
    }

    // XOR 합이 0이면 이미 패배 상태
    if(nim_sum == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;

    // 각 돌 더미에서 가능한 승리 수 계산
    for(int i = 0; i < n; i++)
    {
        int target = nim_sum ^ stones[i]; // 목표 상태
        int remove = stones[i] - target; // 제거해야 할 돌의 개수

        // 제거 가능한 범위 확인
        if(remove >= 1 && remove <= stones[i])
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}