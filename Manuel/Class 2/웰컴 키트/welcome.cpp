#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    vector<long long> sizes(6);
    for(int i = 0; i < 6; i++)
    {
        cin >> sizes[i];
    }

    long long T, P;
    cin >> T >> P;

    long long total_tshirt_bundles = 0;
    for(long long count : sizes)
    {
        if(count == 0)
            continue;
        long long bundles_for_this_size = (count + T - 1) / T;
        total_tshirt_bundles += bundles_for_this_size;
    }
    cout << total_tshirt_bundles << "\n";

    long long pen_bundles = N / P;
    long long remaining_pens = N % P;
    cout << pen_bundles << " " << remaining_pens << "\n";

    return 0;
}