#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;
    int s_mask = 0;

    for(int i = 0; i < M; i++)
    {
        string op;
        cin >> op;

        if(op == "add")
        {
            int x;
            cin >> x;
            s_mask |= (1 << (x - 1));
        }
        else if(op == "remove")
        {
            int x;
            cin >> x;
            s_mask &= ~(1 << (x - 1));
        }
        else if(op == "check")
        {
            int x;
            cin >> x;
            if((s_mask & (1 << (x - 1))) != 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if(op == "toggle")
        {
            int x;
            cin >> x;
            s_mask ^= (1 << (x - 1));
        }
        else if(op == "all")
        {
            s_mask = (1 << 20) - 1;
        }
        else if(op == "empty")
        {
            s_mask = 0;
        }
    }

    return 0;
}