#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

long long getGrundy(long long n)
{
    /*
    패턴: 0, 1, 2, 4, 3, 5, 6, 8, 7, 9, 10, 12, 11, ...
    
    0을 제외하고 4개씩 그룹화하면:
    1  2  4  3
    5  6  8  7  
    9  10 12 11
    ...
    
    규칙:
    - n % 4 == 1: n 그대로
    - n % 4 == 2: n 그대로  
    - n % 4 == 3: n + 1
    - n % 4 == 0: n - 1 (n > 0일 때)
    */

    if(n == 0)
    {
        return 0;
    }

    int remainder = n % 4;

    if(remainder == 1 || remainder == 2)
    {
        return n;
    }
    else if(remainder == 3)
    {
        return n + 1;
    }
    else // remainder == 0
    {
        return n - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    long long nimSum = 0;

    for(int i = 0; i < n; i++)
    {
        long long stone;
        cin >> stone;
        nimSum ^= getGrundy(stone);
    }

    if(nimSum != 0)
    {
        cout << "koosaga" << endl;
    }
    else
    {
        cout << "cubelover" << endl;
    }

    return 0;
}