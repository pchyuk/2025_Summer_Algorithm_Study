#include <iostream>
#include <string>
#include <stack>

using namespace std;

string is_vps(const string& ps_string)
{
    stack<char> s;
    
    for(char ch : ps_string)
    {
        if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            if(s.empty())
            {
                return "NO";
            }
            s.pop();
        }
    }

    if(s.empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        string ps_string;
        cin >> ps_string;
        cout << is_vps(ps_string) << "\n";
    }
    
    return 0;
}