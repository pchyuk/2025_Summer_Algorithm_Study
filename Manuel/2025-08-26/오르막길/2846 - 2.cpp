#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);

    for(int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int max_uphill = 0;
    int current_uphill = 0;

    for(int i = 0; i < n - 1; i++)
    {
        if(heights[i] < heights[i + 1])
        {
            current_uphill += heights[i + 1] - heights[i];
            max_uphill = max(max_uphill, current_uphill);
        }
        else
        {
            current_uphill = 0;
        }
    }
    cout << max_uphill << endl;
    return 0;
}