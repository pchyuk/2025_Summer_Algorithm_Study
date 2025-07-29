#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while(getline(cin, line))
    {
        cout << line << "\n";
    }
    
    return 0;
}