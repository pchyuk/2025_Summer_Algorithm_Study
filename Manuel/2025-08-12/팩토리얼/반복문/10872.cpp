#include <iostream>
#define endl "\n"

using namespace std;

long long factorial(int n)
{
    long long result = 1;
    for(int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cout << factorial(N) << endl;
    return 0;
}