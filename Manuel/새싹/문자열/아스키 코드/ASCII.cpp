#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char char_input;
    cin >> char_input;

    int ascii_value = static_cast<int>(char_input);

    cout << ascii_value << "\n";

    return 0;
}