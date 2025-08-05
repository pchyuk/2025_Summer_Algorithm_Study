#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;
    vector<long long> trees(N);
    long long max_height = 0;
    
    for(int i = 0; i < N; i++)
    {
        cin >> trees[i];
        if(trees[i] > max_height)
        {
            max_height = trees[i];
        }
    }

    long long start = 0;
    long long end = max_height;
    long long result = 0;

    while(start <= end)
    {
        long long mid = start + (end - start) / 2;
        long long cut_length = 0;

        for(long long tree_height : trees)
        {
            if(tree_height > mid)
            {
                cut_length += tree_height - mid;
            }
        }
        if(cut_length >= M)
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}