#include <iostream>
#define endl "\n"

using namespace std;

long long factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
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