#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> scores(N);

    for(int i = 0; i < N; i++)
    {
        cin >> scores[i];
    }
    
    int max_score = *max_element(scores.begin(), scores.end());

    double new_sum = 0.0;

    for(int i = 0; i < N; i++)
    {
        new_sum += (static_cast<double>(scores[i]) / max_score) * 100.0;
    }

    double new_average = new_sum / N;

    cout << new_average << "\n";

    return 0;
}