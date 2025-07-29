#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    unordered_map<int, int> card_counts;

    for(int i = 0; i < N; i++)
    {
        int card_num;
        cin >> card_num;
        card_counts[card_num]++;
    }

    int M;
    cin >> M;
    vector<int> results;
    results.reserve(M);

    for(int i = 0; i < M; i++)
    {
        int query_num;
        cin >> query_num;

        if(card_counts.count(query_num))
        {
            results.push_back(card_counts[query_num]);
        }
        else
        {
            results.push_back(0);
        }
    }

    for(int i = 0; i < M; i++)
    {
        cout << results[i] << (i == M - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}