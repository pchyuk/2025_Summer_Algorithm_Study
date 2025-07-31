#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if(j == i)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }

    int max_sum = 0;
    for(int j = 0; j < n; j++)
    {
        if(triangle[n - 1][j] > max_sum)
        {
            max_sum = triangle[n - 1][j];
        }
    }

    cout << max_sum << "\n";

    return 0;
}