#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;
    
    int length = word.length();
    cout << length << "\n";

    return 0;
}