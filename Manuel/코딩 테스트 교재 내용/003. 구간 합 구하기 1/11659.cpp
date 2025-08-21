#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int suNo, quizNo;
    cin >> suNo >> quizNo;

    vector<long long> prefix_sum(suNo + 1, 0);
    long long temp = 0;
    
    for(int i = 1; i <= suNo; i++)
    {
        int number;
        cin >> number;
        temp += number;
        prefix_sum[i] = temp;
    }
    for(int i = 0; i < quizNo; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << prefix_sum[e] - prefix_sum[s - 1] << endl;
    }

    return 0;
}