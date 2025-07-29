#include <iostream>

using namespace std;

int main()
{
    int square_sum = 0;
    int num;

    for(int i = 0; i < 5; i++)
    {
        cin >> num;
        square_sum += (num * num);
    }

    int verification = square_sum % 10;

    cout << verification << "\n";

    return 0;
}