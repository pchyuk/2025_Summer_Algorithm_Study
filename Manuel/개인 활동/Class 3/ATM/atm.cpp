#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> times(N);
    for(int i = 0; i < N; i++)
    {
        cin >> times[i];
    }
    sort(times.begin(), times.end());

    long long total_waiting_time = 0;
    long long current_time = 0;

    for(int i = 0; i < N; i++)
    {
        current_time += times[i];
        total_waiting_time += current_time;
    }
    
    cout << total_waiting_time << "\n";

    return 0;
}