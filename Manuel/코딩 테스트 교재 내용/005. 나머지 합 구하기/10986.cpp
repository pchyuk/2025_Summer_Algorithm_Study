#include <iostream>
#include <vector>
#include <numeric>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<long long> S(n, 0);
    vector<long long> C(m, 0);
    long long answer = 0;

    int num;
    cin >> num;
    S[0] = num;

    for(int i = 1; i < n; i++)
    {
        cin >> num;
        S[i] = S[i - 1] + num;
    }

    for(int i = 0; i < n; i++)
    {
        int remainder = S[i] % m;
        if(remainder == 0)
        {
            answer++;
        }
        C[remainder]++;
    }

    for(int i = 0; i < m; i++)
    {
        if(C[i] > 1)
        {
            answer += (C[i] * (C[i] - 1) / 2);
        }
    }
    cout << answer << endl;

    return 0;
}