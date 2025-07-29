#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    queue<int> people;
    for(int i = 1; i <= N; i++)
    {
        people.push(i);
    }

    vector<int> josephus_sequence;
    josephus_sequence.reserve(N);

    while(!people.empty())
    {
        for(int i = 0; i < K - 1; i++)
        {
            people.push(people.front());
            people.pop();
        }
        josephus_sequence.push_back(people.front());
        people.pop();
    }

    cout << "<";
    for(size_t i = 0; i < josephus_sequence.size(); i++)
    {
        cout << josephus_sequence[i];
        if(i < josephus_sequence.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << ">\n";

    return 0;
}