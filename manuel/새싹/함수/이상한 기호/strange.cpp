#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    long long result = (a + b) * (a - b);

    cout << result << "\n";

    return 0;
}