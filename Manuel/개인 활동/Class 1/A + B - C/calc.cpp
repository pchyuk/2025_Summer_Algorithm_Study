#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int result_num = a + b - c;
    cout << result_num << "\n";

    string A = to_string(a);
    string B = to_string(b);
    string C = to_string(c);
    string combined_str = A + B;

    long long combined_num = stoll(combined_str);
    long long result_string = combined_num - stoll(C);

    cout << result_string << "\n";

    return 0;
}