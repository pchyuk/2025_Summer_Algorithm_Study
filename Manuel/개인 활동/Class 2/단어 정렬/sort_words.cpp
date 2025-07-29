#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compareWords(const string& a, const string& b)
{
    if(a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> words;
    words.reserve(n);

    for(int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), compareWords);
    words.erase(unique(words.begin(), words.end()), words.end());

    for(const string& word : words)
    {
        cout << word << "\n";
    }
    return 0;
}