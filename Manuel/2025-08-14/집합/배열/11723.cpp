#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    vector<bool> s(21, false);

    while(m--)
    {
        string command;
        cin >> command;

        if(command == "add")
        {
            int x;
            cin >> x;
            s[x] = true;
        }
        else if(command == "remove")
        {
            int x;
            cin >> x;
            s[x] = false;
        }
        else if(command == "check")
        {
            int x;
            cin >> x;
            if(s[x])
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if(command == "toggle")
        {
            int x;
            cin >> x;
            s[x] = !s[x];
        }
        else if(command == "all")
        {
            for(int i = 1; i <= 20; i++)
            {
                s[i] = true;
            }
        }
        else if(command == "empty")
        {
            for(int i = 1; i <= 20; i++)
            {
                s[i] = false;
            }
        }
    }
    return 0;
}