#include <iostream>

using namespace std;

long long calculate_gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return calculate_gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num1, num2;
    cin >> num1 >> num2;

    long long gcd_value = calculate_gcd(num1, num2);
    long long lcm_value = (num1 * num2) / gcd_value;

    cout << gcd_value << "\n" << lcm_value << "\n";

    return 0;
}