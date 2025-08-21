#include <iostream>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count = 1;
    int start_index = 1;
    int end_index = 1;
    long long sum = 1;

    while(end_index != n)
    {
        if(sum == n)
        {
            count++;
            end_index++;
            sum += end_index;
        }
        else if(sum > n)
        {
            sum -= start_index;
            start_index++;
        }
        else
        {
            end_index++;
            sum += end_index;
        }
    }
    
    cout << count << endl;
}