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
    long long nim_sum = 0;

    for(int i = 0; i < n; i++)
    {
        long long p;
        cin >> p;

        if(p % 2 == 0)
        {
            nim_sum ^= p / 2 - 1;
        }
        else
        {
            nim_sum ^= p / 2 + 1;
        }
    }

    if(nim_sum != 0)
    {
        cout << "koosaga" << endl;
    }
    else
    {
        cout << "cubelover" << endl;
    }
    return 0;
}