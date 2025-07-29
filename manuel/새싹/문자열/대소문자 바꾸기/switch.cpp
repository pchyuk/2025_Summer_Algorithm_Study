#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;
    string result = "";

    for(size_t i = 0; i < word.length(); i++)
    {
        char current = word[i];
        if(islower(current))
            result += static_cast<char>(toupper(current));
        else if(isupper(current))
            result += static_cast<char>(tolower(current));
        else
            result += current;
    }

    cout << result << "\n";

    return 0;
}