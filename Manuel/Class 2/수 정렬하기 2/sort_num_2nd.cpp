#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < n; i++)
    {
        cout << numbers[i] << "\n";
    }

    return 0;
}