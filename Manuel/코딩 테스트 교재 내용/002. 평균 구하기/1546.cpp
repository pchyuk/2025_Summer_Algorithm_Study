#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<double> scores(N);
    double max_score = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> scores[i];
        if(scores[i] > max_score)
        {
            max_score = scores[i];
        }
    }

    double sum_scores = 0;
    for(double score : scores)
    {
        sum_scores += score;
    }

    double result = sum_scores * 100 / max_score / N;
    
    cout << result << endl;
    
    return 0;
}