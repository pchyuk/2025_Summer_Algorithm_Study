#include <iostream>
#include <vector>

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

    for(int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        
        for(int j = i + 1; j < n; j++)
        {
            if(numbers[j] < numbers[min_index])
            {
                min_index = j;
            }
        }

        int temp = numbers[i];
        numbers[i] = numbers[min_index];
        numbers[min_index] = temp;
    }

    for(int i = 0; i < n; i++)
    {
        cout << numbers[i] << "\n";
    }
    
    return 0;
}