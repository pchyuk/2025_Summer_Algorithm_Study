#include <iostream>
#define endl "\n"

using namespace std;

long long A, B, C;

long long power(long long base, long long exp)
{
    if(exp == 0)
    {
        return 1;
    }
    
    long long temp = power(base, exp / 2) % C;

    if(exp % 2 == 0)
    {
        return (temp * temp) % C;
    }
    else
    {
        return ((temp * temp) % C * (base % C)) % C; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;
    cout << power(A, B) << endl;

    return 0;
}