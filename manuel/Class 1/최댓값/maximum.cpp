#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers(9);

    for(int i = 0; i < 9; i++)
    {
        cin >> numbers[i];
    }

    vector<int>::iterator max_it = max_element(numbers.begin(), numbers.end());

    int max_value = *max_it;
    int max_index = distance(numbers.begin(), max_it) + 1;

    cout << max_value << "\n";
    cout << max_index << "\n";

    return 0;
}