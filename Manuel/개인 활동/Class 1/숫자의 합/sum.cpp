#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string numbers_str;
    cin >> numbers_str;

    int total_sum = 0;

    for(size_t i = 0; i < numbers_str.length(); i++)
    {
        total_sum += (numbers_str[i] - '0');
    }

    cout << total_sum << "\n";

    return 0;
}