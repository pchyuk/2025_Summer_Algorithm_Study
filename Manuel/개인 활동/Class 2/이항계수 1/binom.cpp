#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    if(K < 0 || K > N)
    {
        cout << 0 << "\n";
        return 0;
    }

    K = min(K, N - K);
    if(K == 0)
    {
        cout << 1 << "\n";
        return 0;
    }

    long long result = 1;

    for(int i = 0; i < K; i++)
    {
        result *= (N - i);
        result /= (i + 1);
    }
    cout << result << "\n";

    return 0;
}