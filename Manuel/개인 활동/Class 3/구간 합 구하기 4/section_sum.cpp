#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> pre_sum(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        pre_sum[i] = pre_sum[i - 1] + num;
    }

    for(int q = 0; q < m; q++)
    {
        int a, b;
        cin >> a >> b;
        int result = pre_sum[b] - pre_sum[a - 1];
        cout << result << "\n";
    }

    return 0;
}