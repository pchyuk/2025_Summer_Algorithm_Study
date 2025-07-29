#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        string S;
        cin >> S;

        char first = S[0];
        char last = S[S.length() - 1];

        cout << first << last << "\n";
    }

    return 0;
}