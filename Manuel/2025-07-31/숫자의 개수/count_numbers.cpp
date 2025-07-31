#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;
    long long product = A * B * C;

    string str_product = to_string(product);
    vector<int> counts(10, 0);

    for(char char_digit : str_product)
    {
        int digit = char_digit - '0';
        counts[digit]++;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << counts[i] << "\n";
    }

    return 0;
}