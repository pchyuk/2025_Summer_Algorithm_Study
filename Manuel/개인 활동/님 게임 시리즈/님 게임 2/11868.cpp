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

    int xor_sum = 0;

    for(int i = 0; i < n; i++)
    {
        int stone;
        cin >> stone;
        xor_sum ^= stone;
    }

    if(xor_sum != 0)
    {
        cout << "koosaga" << endl;
    }
    else
    {
        cout << "cubelover" << endl;
    }
    
    return 0;
}