#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num1, num2;
    cin >> num1 >> num2;

    long long gcd_value = gcd(num1, num2);
    long long lcm_value = lcm(num1, num2);

    cout << gcd_value << "\n" << lcm_value << "\n";
}