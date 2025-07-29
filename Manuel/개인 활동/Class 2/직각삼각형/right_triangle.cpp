#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true)
    {
        vector<int> lengths(3);
        cin >> lengths[0] >> lengths[1] >> lengths[2];

        if(lengths[0] == 0 && lengths[1] == 0 && lengths[2] == 0)
            break;

        sort(lengths.begin(), lengths.end());

        long long a_squared = static_cast<long long>(pow(lengths[0], 2));
        long long b_squared = static_cast<long long>(pow(lengths[1], 2));
        long long c_squared = static_cast<long long>(pow(lengths[2], 2));

        if(a_squared + b_squared == c_squared)
        {
            cout << "right" << "\n";
        }
        else
        {
            cout << "wrong" << "\n";
        }
    }
    return 0;
}