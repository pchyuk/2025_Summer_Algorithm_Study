#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    string n_str;
    cin >> n_str;
    string numbers_str;
    cin >> numbers_str;

    long long sum = 0;
    for(char c : numbers_str)
    {
        sum += c - '0';
    }

    cout << sum << endl;

    return 0;
}