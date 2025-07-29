#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> never_heard;
    never_heard.reserve(N);

    for(int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        never_heard.insert(name);
    }

    vector<string> never_heard_seen;
    never_heard.reserve(min(N, M));

    for(int i = 0; i < M; i++)
    {
        string name;
        cin >> name;
        if(never_heard.count(name))
        {
            never_heard_seen.push_back(name);
        }
    }

    sort(never_heard_seen.begin(), never_heard_seen.end());
    cout << never_heard_seen.size() << "\n";

    for(const string& name : never_heard_seen)
    {
        cout << name << "\n";
    }

    return 0;
}